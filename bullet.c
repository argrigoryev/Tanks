#include <ncurses.h>
#include <unistd.h>
#include <pthread.h>

#include "bullet.h"
#include "tank.h"

extern struct tank tank1;
extern struct tank tank2;
extern pthread_mutex_t mutex;

void shootBullet(struct tank* tank) {
    tank->bullet.isFlying = 1;
    tank->bullet.x = tank->position.x;
    tank->bullet.y = tank->position.y;
    switch (tank->cannonOrientation) {
        case CANNON_RIGHT:
            tank->bullet.dx = 1;
            tank->bullet.dy = 0;
            break;

        case CANNON_LEFT:
            tank->bullet.dx = -1;
            tank->bullet.dy = 0;
            break;

        case CANNON_UP:
            tank->bullet.dx = 0;
            tank->bullet.dy = -1;
            break;

        case CANNON_DOWN:
            tank->bullet.dx = 0;
            tank->bullet.dy = 1;
            break;

        case CANNON_RIGHT_UP:
            tank->bullet.dx = 1;
            tank->bullet.dy = -1;
            break;

        case CANNON_LEFT_DOWN:
            tank->bullet.dx = -1;
            tank->bullet.dy = 1;
            break;

        case CANNON_RIGHT_DOWN:
            tank->bullet.dx = 1;
            tank->bullet.dy = 1;
            break;

        case CANNON_LEFT_UP:
            tank->bullet.dx = -1;
            tank->bullet.dy = -1;
            break;
    }
}

int biundariesCollision(struct tank* tank) {
    return tank->bullet.x > COLS || tank->bullet.x < 0 || tank->bullet.y > LINES || tank->bullet.y < 0;
}

int bulletsCrossedCollision() {
    return tank1.bullet.x == tank2.bullet.x && tank1.bullet.y == tank2.bullet.y;
}

void clearBullet(struct tank* tank) {
    tank->bullet.dx = 0;
    tank->bullet.dy = 0;
    tank->bullet.x = 0;
    tank->bullet.y = 0;
    tank->bullet.isFlying = 0;
}

int tankWasHit(struct tank* tank, struct tank* other) {
    return (other->bullet.x == tank->position.x+3 ||
            other->bullet.x == tank->position.x-3) ||
            (other->bullet.y == tank->position.y+3 ||
            other->bullet.y == tank->position.y-3);
}

void bulletCollision() {
    // boundaries
    if (biundariesCollision(&tank1)) {
        clearBullet(&tank1);
    }
    if (biundariesCollision(&tank2)) {
        clearBullet(&tank2);
    }
    // bullets crossed
    if (bulletsCrossedCollision()) {
        clearBullet(&tank1);
        clearBullet(&tank2);
    }
    // tank1 was hit
    if (tankWasHit(&tank1, &tank2)) {
        tank2.isWinner = 1;
    }
    // tank2 was hit
    if (tankWasHit(&tank2, &tank1)) {
        tank1.isWinner = 1;
    }
}

void *bulletFly(void *none) {
    while (TRUE) {
        if (tank1.bullet.isFlying) {
            usleep(50000);
            tank1.bullet.x += tank1.bullet.dx;
            tank1.bullet.y += tank1.bullet.dy;
        }
        if (tank2.bullet.isFlying) {
            usleep(50000);
            tank2.bullet.x += tank2.bullet.dx;
            tank2.bullet.y += tank2.bullet.dy;
        }
        bulletCollision();
    }
}

void showBullets() {
    if (tank1.bullet.isFlying) {
        mvaddch(tank1.bullet.y, tank1.bullet.x, '+');
    }
    if (tank2.bullet.isFlying) {
        mvaddch(tank2.bullet.y, tank2.bullet.x, '+');
    }
    refresh();
}
