#include <stdio.h>
#include <ncurses.h>
#include <string.h>
#include <pthread.h>

#include "tank.h"
#include "bullet.h"
#include "network.h"

struct tank tank1;
struct tank tank2;

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void initTanks(char ip1[], char ip2[]) {
    pthread_mutex_lock( &mutex );
    // ip
    tank1.ip = ip1;
    tank2.ip = ip2;
    // position
    tank1.position.x = 10;
    tank1.position.y = LINES / 2;
    tank2.position.x = COLS - 11;
    tank2.position.y = LINES / 2;
    // orientation
    tank1.orientation = HORIZONTAL;
    tank2.orientation = HORIZONTAL;
    // cannon
    tank1.cannonOrientation = CANNON_RIGHT;
    tank2.cannonOrientation = CANNON_LEFT;
    // win
    tank1.isWinner = FALSE;
    tank2.isWinner = FALSE;
    pthread_mutex_unlock( &mutex );
}

void showWinner() {
    clear();
    char *text;
    if (tank1.isWinner) {
        text = "Tank 1 won!";
    } else if (tank2.isWinner) {
        text = "Tank 2 won!";
    }
    mvaddstr(LINES / 2, COLS / 2, text);
    refresh();
}

int isIpCorrect(char ip[]) {
    return strlen(ip) == 12 && ip[3] == '.' && ip[7] == '.' && ip[9] == '.';
}

int main(int argc, char* argv[]) {

    // check arguments
    if (argc != 3) {
        perror("Incorrect parameters");
        return __LINE__;
    }

    // check ip
//    if (!isIpCorrect(argv[1]) || !isIpCorrect(argv[2])) {
//        perror("Incorrect IP");
//        return __LINE__;
//    }

    // init ncurses
    initscr();
    noecho();
    keypad(stdscr, TRUE);
    curs_set(0);

    // init tanks
    initTanks(argv[1], argv[2]);

    // init key listener
    pthread_t pidKeyListener;
    void *retvalKeyListener;
    pthread_create(&pidKeyListener, NULL, listenToKeys, NULL);

    // init network listener
    pthread_t pidNetworkListener;
    void* retvalNetworkListener;
    pthread_create(&pidNetworkListener, NULL, listenToNetwork, NULL);

    // init bullet
    pthread_t pidBulletFly;
    void* retvalBulletFly;
    pthread_create(&pidBulletFly, NULL, bulletFly, NULL);

    // check winner
    while (!tank1.isWinner && !tank2.isWinner) {
        clear();
        showTanks();
        showBullets();
    }

    // show winner
    showWinner();

    // join threads
    pthread_join(pidKeyListener, &retvalKeyListener);
    pthread_join(pidNetworkListener, &retvalNetworkListener);
    pthread_join(pidBulletFly, &retvalBulletFly);

    // stop library & stop program
    endwin();

    return 0;
}
