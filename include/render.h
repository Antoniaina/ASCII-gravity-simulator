#ifndef RENDER_H
#define RENDER_H

#define HUD_WIDTH 30
#define HUD_HEIGHT 24
#define SIM_WIDTH 80
#define SIM_HEIGHT 24
#define TOTAL_HEIGHT 24 + 3  //80 40
#define TOTAL_WIDTH (HUD_WIDTH + SIM_WIDTH + 4) 
#define COLOR_LEN 10

#define RED_COLOR "\033[31m"
#define GREEN_COLOR "\033[32m"
#define YELLOW_COLOR "\033[33m"
#define BLUE_COLOR "\033[34m"
#define MAGENTA_COLOR "\033[35m"
#define CYAN_COLOR "\033[36m"
#define WHITE_COLOR "\033[37m"

typedef struct {
    char c;
    char color[COLOR_LEN];
} Cell;

typedef struct {
    char label[32];
    char value[32];
    char unit[16];
} HudEntry;


void initBuffer(Cell screen[TOTAL_HEIGHT][TOTAL_WIDTH]);
void drawBuffer(Cell screen[TOTAL_HEIGHT][TOTAL_WIDTH]);
void drawChar(Cell screen[TOTAL_HEIGHT][TOTAL_WIDTH], int x, int y, char c, const char *color);
void drawHUD(Cell screen[TOTAL_HEIGHT][TOTAL_WIDTH], const char *title, HudEntry *entries, int paramsCount);
void drawSimulationChar(Cell screen[TOTAL_HEIGHT][TOTAL_WIDTH], int x, int y, char c, const char *color);
void renderFrame(Cell scree[TOTAL_HEIGHT][TOTAL_WIDTH]);

#endif