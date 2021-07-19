#ifndef _TANK_SUPER_HEADER_
#define _TANK_SUPER_HEADER_

#define HORIZONTAL 0
#define VERTICAL 1

#define CANNON_RIGHT 0
#define CANNON_RIGHT_UP 1
#define CANNON_RIGHT_DOWN 2
#define CANNON_UP 3
#define CANNON_LEFT 4
#define CANNON_LEFT_UP 5
#define CANNON_LEFT_DOWN 6
#define CANNON_DOWN 7

struct bullet {
    int x;
    int y;
    int dx;
    int dy;
    int isFlying;
};

struct tank {
    struct position {
        int x;
        int y;
    } position;
    int orientation;
    int cannonOrientation;
    char *ip;
    int isWinner;
    struct bullet bullet;
};

int isPlayer(char ip[]);
struct tank * tankWithIp(char ip[]);

void showTanks();
void setTower(int y, int x, int orientation);
void setTracks(int towerY, int towerX, int orientation);
void setCannon(int towerY, int towerX, int orientation, int cannonOrientation);

#endif