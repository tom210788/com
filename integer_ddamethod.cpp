#include <stdio.h>
#include <graphics.h>

void drawLineIntegerDDA(int x1, int y1, int x2, int y2) {
    int dx, dy, steps, k;
    int x, y, xIncrement, yIncrement;

   
    dx = x2 - x1;
    dy = y2 - y1;

    steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);

    xIncrement = dx / steps;
    yIncrement = dy / steps;

    
    x = x1;
    y = y1;

    putpixel(x, y, WHITE);

    for (k = 0; k < steps; k++) {
        x += xIncrement;
        y += yIncrement;

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

    drawLineIntegerDDA(x1, y1, x2, y2);

    delay(5000); 
    closegraph();

    return 0;
}

