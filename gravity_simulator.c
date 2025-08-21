#include <stdio.h>
#include <unistd.h>

int main() {
    double y = 10.0;    
    double v = 0.0;     
    double g = 9.81;    
    double dt = 0.05;   
    double e = 0.9;     

    for (int step = 0; step < 200; step++) {
        
        v -= g * dt;
        y += v * dt;
 
        if (y < 0) {
            y = 0;
            v = -v * e;
        }

        
        int pos = (int)(y + 0.5);
        for (int i = 0; i < pos; i++) printf(" ");
        printf("o\n");

        usleep(50000); 
    }
}
