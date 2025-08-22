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
    system("cls");
    for (int i=0; i<HEIGHT; i++) {
        for (int j=0; j<WIDTH; j++) {
            putchar(screen[i][j]);
        }
        putchar('\n');
    }
}

void drawChar(char screen[HEIGHT][WIDTH], int x, int y, char c) {
    if (x>=0 && x<HEIGHT && y>=0 && y<WIDTH) {
        screen[y][x] = c;
    } 
} 