#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "render.h"

void initBuffer(char screen[HEIGHT][WIDTH]) {
    for (int i=0; i<HEIGHT; i++) {
        for (int j=0; j<WIDTH; j++) {
            screen[i][j] = ' ';
        }
    }
}

void drawBuffer( char screen[HEIGHT][WIDTH]) {
    printf("\033[H");    
    printf("\033[?25l");

    for (int j = 0; j < WIDTH + 2; j++) printf("-");
    putchar('\n');

    for (int i=0; i<HEIGHT; i++) {
        printf("|");
        for (int j=0; j<WIDTH; j++) {
            putchar(screen[i][j]);
        }
        printf("|\n");
    }

    for (int j = 0; j < WIDTH + 2; j++) printf("-");
    putchar('\n');

    fflush(stdout);
}

void drawChar(char screen[HEIGHT][WIDTH], int x, int y, char c) {
    if (x>=0 && x<HEIGHT && y>=0 && y<WIDTH) {
        screen[y][x] = c;
    } 
} 