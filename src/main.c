#include <stdio.h>
#include <time.h>
#include "render.h"
#include "engine.h"

#define GRAVITY 9.81f
#define RESTITUTION 0.8f

struct timespec ts = {0, 80 * 1000000};

int main() {
    Engine engine;
    initEngine(&engine);

    Cell screen[TOTAL_HEIGHT][TOTAL_WIDTH];
    
    HudEntry params[] = {
            {"Temps", "", "s"},
            {"Vx", "", "m/s"},
            {"Vy", "", "m/s"},
            {"x", "", "m"},
            {"y", "", "m"},
            {"Gravite", "", "m/s^2"},
            {"Coef restitution", "", "m/s^2"}
        };
    int nbParams = sizeof(params) / sizeof(params[0]);  
    float maxX = TOTAL_WIDTH - HUD_WIDTH - 1;
    float maxY = TOTAL_HEIGHT - 1;

    while ((1)) {
        float dt = 0.01f;
        updateEngine(&engine, dt, GRAVITY, maxX, maxY, RESTITUTION);

        snprintf(params[0].value, sizeof(params[0].value), "%.2f", engine.time);
        snprintf(params[1].value, sizeof(params[1].value), "%.2f", engine.balls[0].vx);
        snprintf(params[2].value, sizeof(params[2].value), "%.2f", engine.balls[0].vy);
        snprintf(params[3].value, sizeof(params[3].value), "%.2f", engine.balls[0].x);
        snprintf(params[4].value, sizeof(params[4].value), "%.2f", engine.balls[0].y);
        snprintf(params[5].value, sizeof(params[5].value), "%.2f", GRAVITY);
        snprintf(params[6].value, sizeof(params[6].value), "%.2f", RESTITUTION);

        initBuffer(screen);
        drawHUD(screen, "Simulation", params, nbParams);
        drawSimulationChar(screen, &engine, 'O', RED_COLOR);
        renderFrame(screen);

        nanosleep(&ts, NULL);
    }

    printf(SHOW_CURSOR RESET_COLOR);
    return 0;
}