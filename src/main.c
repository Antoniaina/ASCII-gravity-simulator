#include <stdio.h>
#include <time.h>
#include "render.h"

struct timespec ts = {0, 80 * 1000000};

int main() {
    Cell screen[TOTAL_HEIGHT][TOTAL_WIDTH];
    HudEntry params[] = {
        {"Temps", "12.3", "s"},
        {"Vitesse", "45.0", "m/s"},
        {"Hauteur", "120", "m"},
    };
    int nbParams = sizeof(params) / sizeof(params[0]);

     for (int frame = 0; frame < 100; frame++) {
        initBuffer(screen);

        char timeStr[16];
        snprintf(timeStr, sizeof(timeStr), "%.1f", frame * 0.1);
        snprintf(params[0].value, sizeof(params[0].value), "%.1f", frame * 0.1);

        drawHUD(screen, "Ball Simulation", params, nbParams);

        int ballX = frame % (TOTAL_WIDTH - HUD_WIDTH - 2);
        int ballY = TOTAL_HEIGHT / 2;
        drawSimulationChar(screen, ballX, ballY, 'O', RED_COLOR);

        renderFrame(screen);
        nanosleep(&ts, NULL);
    }

    printf(SHOW_CURSOR RESET_COLOR);
    return 0;
}