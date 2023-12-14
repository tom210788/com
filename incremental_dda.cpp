#include <graphics.h>
#include <math.h>


void drawLineIncrementalDDA(int x1, int y1, int x2, int y2) {
    int dx, dy, steps, k;
    float xIncrement, yIncrement, x, y;

    dx = x2 - x1;
    dy = y2 - y1;

  	 
    steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);

    
    xIncrement = (float)dx / (float)steps;
    yIncrement = (float)dy / (float)steps;

    
    x = x1;
    y = y1;

    
   putpixel(lround(x), lround(y), WHITE);

   
    for (k = 0; k < steps; k++) {
        x += xIncrement;
        y += yIncrement;

        
      putpixel(lround(x), lround(y), WHITE);
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

    drawLineIncrementalDDA(x1, y1, x2, y2);

    delay(5000); 
    closegraph();

    return 0;
}

