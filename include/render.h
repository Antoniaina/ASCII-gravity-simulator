#ifndef RENDER_H
#define RENDER_H

#define WIDTH 80 //80 24
#define HEIGHT 24
#define COLOR_LEN 10

typedef struct {
    char c;
    char color[COLOR_LEN];
} Cell;

void initBuffer(Cell screen[HEIGHT][WIDTH]);
void drawBuffer(Cell screen[HEIGHT][WIDTH]);
void drawChar(Cell screen[HEIGHT][WIDTH], int x, int y, char c, const char *color);

#endif