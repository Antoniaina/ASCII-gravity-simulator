#ifndef PHYSICS_H
#define PHYSICS_H

typedef struct {
    float x, y;
    float vx, vy;
} Ball;

void updateBall(Ball *ball, float dt);

#endif
