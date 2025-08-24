#ifndef ENGINE_H
#define ENGINE_H

#include "physics.h"

#define MAX_BALLS 10

typedef struct {
    Ball balls[MAX_BALLS];
    int ballCount;
    float time;
} Engine;

void initEngine(Engine *engine);
void updateEngine(Engine *engine, float dt);

#endif
