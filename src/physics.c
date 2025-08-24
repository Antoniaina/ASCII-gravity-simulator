#include "physics.h"

void updateBall(Ball *ball, float dt) {
    ball->x += ball->vx * dt;
    ball->y += ball->vy * dt;
}
