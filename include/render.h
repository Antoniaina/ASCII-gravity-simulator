#ifndef RENDER_H
#define RENDER_H

#define WIDTH 40
#define HEIGHT 40

void initBuffer(char screen[HEIGHT][WIDTH]);
void drawBuffer(char screen[HEIGHT][WIDTH]);
void drawChar(char screen[HEIGHT][WIDTH], int x, int y, char c);

#endif