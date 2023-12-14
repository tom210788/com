#include <stdio.h>
#include <graphics.h>

void drawCircleBresenham(int xc, int yc, int r) {
    int x = 0, y = r;
    int p = 3 - 2 * r;

    
    putpixel(xc + x, yc - y, WHITE);

   
    while (x <= y) {
        x++;

        if (p > 0) {
            y--;
            p = p + 4 * (x - y) + 10;
        } else {
            p = p + 4 * x + 6;
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

    drawCircleBresenham(xc, yc, r);

    delay(5000); 
    closegraph();

    return 0;
}

