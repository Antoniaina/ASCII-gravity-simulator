#include "physics.h"

void updateBall(Ball *ball, float dt, float g, float maxX, float maxY, float restitution) {
    ball->vy += g * dt;

    ball->y += ball->vy * dt;
    ball->x += ball->vx * dt;

    if (ball->x < 0) {
        ball->x = 1;
        ball->vx = -ball->vx * restitution;
    } else if (ball->x >= maxX) {
        ball->x = maxX-1;
        ball->vx = -ball->vx * restitution;
    }

    if (ball->y < 0) {
        ball->y = 1;
        ball->vy = -ball->vy * restitution;
    } else if (ball->y >= maxY) {
        ball->y = maxY-1;
        ball->vy = -ball->vy * restitution;
    }

}
