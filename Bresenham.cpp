#include <stdio.h>
#include <graphics.h>

void drawLineBresenham(int x1, int y1, int x2, int y2) {
    int dx, dy, x, y, p, incE, incNE;

    
    dx = x2 - x1;
    dy = y2 - y1;

   
    p = 2 * dy - dx;
    incE = 2 * dy;
    incNE = 2 * (dy - dx);

    x = x1;
    y = y1;

    
    putpixel(x, y, WHITE);

  
    while (x < x2) {
        if (p <= 0) {
            p += incE;
        } else {
            p += incNE;
            y++;
        }
        x++;

        putpixel(x, y, WHITE);
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);

    int x1, y1, x2, y2;

    printf("Enter the coordinates of the starting point (x1 y1): ");
    scanf("%d %d", &x1, &y1);

    printf("Enter the coordinates of the ending point (x2 y2): ");
    scanf("%d %d", &x2, &y2);

    drawLineBresenham(x1, y1, x2, y2);

    delay(5000); 
    closegraph();

    return 0;
}

