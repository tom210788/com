#include <stdio.h>
#include <graphics.h>

void drawCircleMidpoint(int xc, int yc, int r) {
    int x = 0, y = r;
    int p = 1 - r;

   
    putpixel(xc + x, yc - y, WHITE);

    
    while (x < y) {
        x++;

        if (p < 0) {
            p += 2 * x + 1;
        } else {
            y--;
            p += 2 * (x - y) + 1;
        }

        putpixel(xc + x, yc - y, WHITE);
        putpixel(xc - x, yc - y, WHITE);
        putpixel(xc + x, yc + y, WHITE);
        putpixel(xc - x, yc + y, WHITE);

        putpixel(xc + y, yc - x, WHITE);
        putpixel(xc - y, yc - x, WHITE);
        putpixel(xc + y, yc + x, WHITE);
        putpixel(xc - y, yc + x, WHITE);
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);

    int xc, yc, r;

    printf("Enter the coordinates of the center (xc yc): ");
    scanf("%d %d", &xc, &yc);

    printf("Enter the radius of the circle: ");
    scanf("%d", &r);

    drawCircleMidpoint(xc, yc, r);

    delay(5000); 
    closegraph();

    return 0;
}

