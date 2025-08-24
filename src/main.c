#include <stdio.h>
#include <Windows.h>
#include "render.h"

int main() {
    Cell screen[HEIGHT][WIDTH];

    int x=5, y=5 ;

    while (1){
       initBuffer(screen);
       drawChar(screen, x, y, 'O', "\033[31m");
       drawBuffer(screen);
       x = (x+1) % WIDTH;
       Sleep(50);
    }
    
    printf("\033[?25h");

    return 0;
}