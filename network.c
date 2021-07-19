#include <sys/types.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/select.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <ncurses.h>

#include "network.h"
#include "tank.h"
#include "bullet.h"

#ifndef PORT
#  define PORT 9999
#endif

extern struct tank tank1;
extern struct tank tank2;
extern pthread_mutex_t mutex;

void onKeyPress(struct tank *tank, int key) {
    switch (key) {
        case KEY_RIGHT:
            if (!(tank->position.x+5 > COLS)) {
                tank->position.x++;
            }
            tank->orientation = HORIZONTAL;
//            tank->cannonOrientation = CANNON_RIGHT;
            break;

        case KEY_LEFT:
            if (!(tank->position.x-3 < 0)) {
                tank->position.x--;
            }
            tank->orientation = HORIZONTAL;
//            tank->cannonOrientation = CANNON_LEFT;
            break;

        case KEY_UP:
            if (!(tank->position.y-2 < 0)) {
                tank->position.y--;
            }
            tank->orientation = VERTICAL;
//            tank->cannonOrientation = CANNON_UP;
            break;

        case KEY_DOWN:
            if (!(tank->position.y+3 > LINES)) {
                tank->position.y++;
            }
            tank->orientation = VERTICAL;
//            tank->cannonOrientation = CANNON_DOWN;
            break;

        case 'd':
            tank->cannonOrientation = CANNON_RIGHT;
            break;

        case 'e':
            tank->cannonOrientation = CANNON_RIGHT_UP;
            break;

        case 'c':
            tank->cannonOrientation = CANNON_RIGHT_DOWN;
            break;

        case 'w':
            tank->cannonOrientation = CANNON_UP;
            break;

        case 'a':
            tank->cannonOrientation = CANNON_LEFT;
            break;

        case 'q':
            tank->cannonOrientation = CANNON_LEFT_UP;
            break;

        case 'z':
            tank->cannonOrientation = CANNON_LEFT_DOWN;
            break;

        case 'x':
            tank->cannonOrientation = CANNON_DOWN;
            break;

        case 's':
            shootBullet(tank);
            break;

        default:
            break;
    }
}

int work_flag = 1;
void* listenToNetwork(void* none) {
    int sock, addr_len, count, ret;
    int buffer;
    fd_set readfd;
    struct sockaddr_in addr;

    sock = socket(AF_INET, SOCK_DGRAM, 0);
    if ( 0 > sock ) {
        perror("socket");
        return NULL;
    }

    addr_len = sizeof(struct sockaddr_in);
    memset((void*)&addr, 0, addr_len);
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = htons(INADDR_ANY);
    addr.sin_port = htons(PORT);

    if ( bind(sock,(struct sockaddr*)&addr, addr_len) < 0) {
        perror("bind");
        close(sock);
        return NULL;
    }

    while (work_flag) {
        FD_ZERO(&readfd);
        FD_SET(sock, &readfd);

        ret = select(sock+1, &readfd, NULL, NULL, 0);
        if (ret > 0) {
            if (FD_ISSET(sock, &readfd)) {
                count = recvfrom(sock, &buffer, 4, 0, (struct sockaddr*)&addr, &addr_len);
                if (count == 4) {
                    // FIXME: test
                    if (isPlayer(inet_ntoa(addr.sin_addr))) {
                        onKeyPress(tankWithIp(inet_ntoa(addr.sin_addr)), buffer);
                    }
                    // FIXME: test
//                    onKeyPress(&tank2, buffer);
                }
            }
        }
    }
    close(sock);
    return (void*)NULL;
}


void* listenToKeys(void *none) {
    int sock, yes = 1;
    struct sockaddr_in addr;
    int addr_len;
    int ret;
    int key;

    sock = socket(AF_INET, SOCK_DGRAM, 0);
    if (sock < 0) {
        perror("sock");
        return -1;
    }

    ret = setsockopt(sock, SOL_SOCKET, SO_BROADCAST, (char*)&yes, sizeof(yes));
    if (ret == -1) {
        perror("setsockopt");
        return 0;
    }

    addr_len = sizeof(struct sockaddr_in);
    memset((void*)&addr, 0, addr_len);
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = htonl(INADDR_BROADCAST);
    addr.sin_port = htons(PORT);

    while(work_flag) {
        key = getch();
        sendto(sock, &key, 4 , 0, (struct sockaddr*) &addr, addr_len);
    }
    close(sock);
}
