#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "render.h"

#define CLEAR_SCREEN "\033[2J"
#define CURSOR_HOME "\033[H"

static Cell prevScreen[TOTAL_HEIGHT][TOTAL_WIDTH]; 
static int prevInitialized = 0;


void drawLine(Cell frame[TOTAL_HEIGHT][TOTAL_WIDTH], int start, int end, int currentLine) {
    drawChar(frame, start, currentLine, '+', FRAME_COLOR);
    drawChar(frame, end, currentLine, '+', FRAME_COLOR);
    
    for (int i=start+1 ; i<end ; i++){
        drawChar(frame, i, currentLine, '-', FRAME_COLOR);
    }
}

void initBuffer(Cell screen[TOTAL_HEIGHT][TOTAL_WIDTH]) {
    for (int i=0; i<TOTAL_HEIGHT; i++) {
        for (int j=0; j<TOTAL_WIDTH; j++) {
            screen[i][j].c = ' ';
            strcpy(screen[i][j].color, RESET_COLOR);
        }
    }

    for (int i=0; i<TOTAL_HEIGHT; i++) {
        for (int j=0; j<TOTAL_WIDTH; j++) {
            if (i!=0 && i!=TOTAL_HEIGHT-1 && (j==0 || j==HUD_WIDTH-1 || j==TOTAL_WIDTH-1)){
                screen[i][j].c = '|';
                strcpy(screen[i][j].color, FRAME_COLOR);
            }
        }
    }

    drawLine(screen, 0, HUD_WIDTH-1, 0);
    drawLine(screen, HUD_WIDTH-1, TOTAL_WIDTH-1, 0);
    drawLine(screen, 0, HUD_WIDTH-1, 2);
    drawLine(screen, 0, HUD_WIDTH-1, TOTAL_HEIGHT-1);
    drawLine(screen, HUD_WIDTH-1, TOTAL_WIDTH-1, TOTAL_HEIGHT-1);

}

void drawChar(Cell screen[TOTAL_HEIGHT][TOTAL_WIDTH], int x, int y, char c, const char *color) {
    if (x>=0 && x<TOTAL_WIDTH && y>=0 && y<TOTAL_HEIGHT) {
        screen[y][x].c = c;
        strncpy(screen[y][x].color, color, COLOR_LEN - 1);
        screen[y][x].color[COLOR_LEN - 1] = '\0' ;
    } 
} 

void drawHUD(Cell screen[TOTAL_HEIGHT][TOTAL_WIDTH], const char *title, HudEntry *entries, int paramsCount) {
    int startX=1, currentY=1 ;

    int titleLen = strlen(title);
    if (titleLen > HUD_WIDTH-2) titleLen = HUD_WIDTH-2;
    int titleStart = (HUD_WIDTH - titleLen - 2) / 2;
    for (int i = 0; i < titleLen; i++) {
        drawChar(screen, titleStart + i, currentY, title[i], CYAN_COLOR);
    }

    currentY+=2;
    for (int i = 0; i < paramsCount && currentY < HUD_HEIGHT - 1; i++, currentY++) {
        int labelLen = strlen(entries[i].label);
        for (int j = 0; j < labelLen && j < HUD_WIDTH - 2; j++) {
            drawChar(screen, startX + 1 + j, currentY, entries[i].label[j], MAGENTA_COLOR);
        }

        char valueStr[64];
        snprintf(valueStr, sizeof(valueStr), " = %s %s", entries[i].value, entries[i].unit);
        int valLen = strlen(valueStr);
        for (int j = 0; j < valLen && (1 + labelLen + j) < HUD_WIDTH - 1; j++) {
            drawChar(screen, startX + 1 + labelLen + j, currentY, valueStr[j], YELLOW_COLOR);
        }
    }

}

void drawSimulationChar(Cell screen[TOTAL_HEIGHT][TOTAL_WIDTH], int x, int y, char c, const char *color) {
    int simX = HUD_WIDTH + x;
    int simY = y;

    if (simX >= HUD_WIDTH && simX < TOTAL_WIDTH && simY >= 0 && simY < TOTAL_HEIGHT) {
        screen[simY][simX].c = c;
        strncpy(screen[simY][simX].color, color, COLOR_LEN - 1);
        screen[simY][simX].color[COLOR_LEN - 1] = '\0';
    }
}

void renderFrame(Cell screen[TOTAL_HEIGHT][TOTAL_WIDTH]) {
    if (!prevInitialized) {
        printf(CLEAR_SCREEN CURSOR_HOME HIDE_CURSOR);
        prevInitialized = 1;
    }

    for (int y = 0; y < TOTAL_HEIGHT; y++) {
        for (int x = 0; x < TOTAL_WIDTH; x++) {
            if (screen[y][x].c != prevScreen[y][x].c || strcmp(screen[y][x].color, prevScreen[y][x].color) != 0) {
                printf("\033[%d;%dH%s%c", y + 1, x + 1, screen[y][x].color, screen[y][x].c);
                prevScreen[y][x] = screen[y][x];
            }
        }
    }

    fflush(stdout);
}
