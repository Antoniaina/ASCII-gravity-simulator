#include<stdio.h>
#include<Windows.h>

#define HEIGHT_MAX 20

int main() {
    double y = 18.0;
    double vy = 0.0;
    double g = 9.81;
    double dt = 0.05;
    double el = 0.8;
    double t = 0.0;
    
    while (1){
        vy -= g * dt;
        y += vy * dt;

        if ( y <= 0 ) {
            y = 0; // TODO: consider the speed at the collision point
            vy = -vy*el;
        }

        int pos = (int)(HEIGHT_MAX - y + 0.5);
        system("cls");
        printf("t=%.2f (s)  |   y=%.2f (m)  |    vy=%.2f (m/s)   \n", t, y, vy);
        printf("-------------------------------------------------\n");
        for (int i=0 ; i<HEIGHT_MAX ; i++) {
            printf(i == pos ? "    O\n" : "\n" );
        }        
        printf("-------------------------------------------------");
        t += dt;
        Sleep(30);
    }
    
}