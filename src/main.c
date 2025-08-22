#include <stdio.h>
#include <Windows.h>
#include "render.h"

int main() {
    char screen[HEIGHT][WIDTH];

    int x=5, y=5 ;

    while (1){
       initBuffer(screen);
       drawChar(screen, x, y, 'O');
       drawBuffer(screen);
       x = (x+1) % WIDTH;
       Sleep(100);
    }
    
    return 0;
}