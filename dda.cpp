#include<stdio.h> 

#include<math.h> 

#include<graphics.h> 

#define round(val) (int)(val+0.5) 



void line_dda(int xa, int ya, int xb, int yb) {

   int Dx = xb - xa, Dy = yb - ya, steps, k;

   float xin, yin, X = xa, Y = ya;

   if (abs(Dx) > abs(Dy))

      steps = abs(Dx);

   else

      steps = abs(Dy);



   xin = Dx / (float) steps;

   yin = Dy / (float) steps;

   putpixel(round(X), round(Y), 6);



   for (k = 0; k < steps; k++) {

      X = X + xin;

      Y = Y + yin;

      putpixel(round(X), round(Y), 6);

   }

}

int main() {

   int gd = DETECT, gm;

   int xa, xb, ya, yb;

   printf("Enter the two values: ");

   scanf("%d%d%d%d", &xa, &ya, &xb, &yb);

   initgraph(&gd, &gm, "");

   cleardevice();

   line_dda(xa, ya, xb, yb);

   getch();

   closegraph();

   return 0;

}
