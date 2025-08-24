#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "render.h"

#define FRAME_COLOR "\033[36m"
#define RESET_COLOR "\033[0m"

void initBuffer(Cell screen[HEIGHT][WIDTH]) {
    for (int i=0; i<HEIGHT; i++) {
        for (int j=0; j<WIDTH; j++) {
            screen[i][j].c = ' ';
            strcpy(screen[i][j].color, RESET_COLOR);
        }
    }
}

void drawBuffer(Cell screen[HEIGHT][WIDTH]) {
    // printf("\033[H\033[J");
    printf("\033[H");    
    printf("\033[?25l");

    printf(FRAME_COLOR "+");
    for (int j = 0; j < WIDTH; j++) printf("-");
    putchar('+');
    printf(RESET_COLOR "\n");

    for (int i=0; i<HEIGHT; i++) {
        printf(FRAME_COLOR "|" RESET_COLOR);
        for (int j=0; j<WIDTH; j++) {
            printf("%s%c" RESET_COLOR, screen[i][j].color, screen[i][j].c);
        }
        printf(FRAME_COLOR "|" RESET_COLOR "\n");
    }

    printf(FRAME_COLOR "+");
    for (int j = 0; j < WIDTH; j++) printf("-");
    putchar('+');
    printf(RESET_COLOR "\n");

    fflush(stdout);
}

void drawChar(Cell screen[HEIGHT][WIDTH], int x, int y, char c, const char *color) {
    if (x>=0 && x<WIDTH && y>=0 && y<HEIGHT) {
        screen[y][x].c = c;
        strncpy(screen[y][x].color, color, COLOR_LEN - 1);
        screen[y][x].color[COLOR_LEN - 1] = '\0' ;
    } 
} 