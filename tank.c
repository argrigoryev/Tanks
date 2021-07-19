#include <ncurses.h>
#include <string.h>
#include <pthread.h>

#include "tank.h"

extern struct tank tank1;
extern struct tank tank2;
extern pthread_mutex_t mutex;

int isPlayer(char ip[]) {
    return strcmp(ip, tank2.ip) || strcmp(ip, tank1.ip);
}

struct tank * tankWithIp(char ip[]) {
    if (strcmp(ip, tank1.ip)) {
        return &tank1;
    } else {
        return &tank2;
    }
}

void showTanks() {
    // tank1
    setTower(tank1.position.y, tank1.position.x, tank1.orientation);
    setTracks(tank1.position.y, tank1.position.x, tank1.orientation);
    setCannon(tank1.position.y, tank1.position.x, tank1.orientation, tank1.cannonOrientation);
    // tank2
    setTower(tank2.position.y, tank2.position.x, tank2.orientation);
    setTracks(tank2.position.y, tank2.position.x, tank2.orientation);
    setCannon(tank2.position.y, tank2.position.x, tank2.orientation, tank2.cannonOrientation);
    refresh();
}

void setTower(int y, int x, int orientation) {
    if (orientation == HORIZONTAL) {
        mvaddstr(y, x, " *");
    } else if (orientation == VERTICAL) {
        mvaddch(y, x, '*');
    }
}

void setTracks(int towerY, int towerX, int orientation) {
    if (orientation == HORIZONTAL) {
        mvaddstr(towerY - 1, towerX - 1, "# # #");
        mvaddstr(towerY + 1, towerX - 1, "# # #");
    } else if (orientation == VERTICAL) {
        int trackSize = 3;
        for (int i = 0; i < trackSize; i++) {
            int y = towerY + i - 1;
            mvaddch(y, towerX - 2, '#');
            mvaddch(y, towerX + 2, '#');
        }
    }

}

void setCannon(int towerY, int towerX, int orientation, int cannonOrientation) {
    switch (cannonOrientation) {
        case CANNON_RIGHT:
            mvaddch(towerY, towerX + 2, '-');
            break;

        case CANNON_LEFT:
            mvaddch(towerY, towerX - 2, '-');
            break;

        case CANNON_UP:
            if (orientation == HORIZONTAL) {
                mvaddstr(towerY - 1, towerX, " |");
            } else if (orientation == VERTICAL) {
                mvaddch(towerY - 1, towerX, '|');
            }
            break;

        case CANNON_DOWN:
            if (orientation == HORIZONTAL) {
                mvaddstr(towerY + 1, towerX, " |");
            } else if (orientation == VERTICAL) {
                mvaddch(towerY + 1, towerX, '|');
            }
            break;

        case CANNON_RIGHT_UP:
            if (orientation == VERTICAL) {
                mvaddch(towerY - 1, towerX + 2, '/');
            } else if (orientation == HORIZONTAL) {
                mvaddstr(towerY - 1, towerX + 2, " /");
            }
            break;

        case CANNON_LEFT_DOWN:
            if (orientation == VERTICAL) {
                mvaddch(towerY + 1, towerX - 2, '/');
            } else if (orientation == HORIZONTAL) {
                mvaddch(towerY + 1, towerX - 1, '/');
            }
            break;

        case CANNON_RIGHT_DOWN:
            if (orientation == VERTICAL) {
                mvaddch(towerY + 1, towerX + 2, '\\');
            } else if (orientation == HORIZONTAL) {
                mvaddch(towerY + 1, towerX + 3, '\\');
            }
            break;

        case CANNON_LEFT_UP:
            if (orientation == VERTICAL) {
                mvaddch(towerY - 1, towerX - 2, '\\');
            } else if (orientation == HORIZONTAL) {
                mvaddch(towerY - 1, towerX - 1, '\\');
            }
            break;
    }
}