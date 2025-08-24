#include "engine.h"
#include <stdlib.h>

void initEngine(Engine *engine) {
    engine->ballCount = 1; 
    engine->balls[0].x = 1.0f;
    engine->balls[0].y = 1.0f;
    engine->balls[0].vx = 5.0f; 
    engine->balls[0].vy = 5.0f; 
    engine->time = 0.0f;
}

void updateEngine(Engine *engine, float dt) {
    for (int i=0 ; i< engine->ballCount; i++) {
        updateBall(&engine->balls[i], dt);
    }
    engine->time += dt;
}
