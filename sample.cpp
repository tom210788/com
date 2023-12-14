#include<graphics.h>
#include<stdio.h>
int main()
{
	float x,y,x1,x2,y1,y2,xe,m,dx,dy,c;
	int gd=DETECT, gm;
	initgraph(&gd, &gm ,"");
	printf("Enter the points x1 and y1:");
	scanf("%f%f",&x1,&y1);
	printf("Enter the points x2 and y2:");
	scanf("%f%f",&x2,&y2);
	dx=x2-x1;
	dy=y2-y2;
	m=dy/dx;
	if(dx>0)
	{
		x=x1;
		y=y1;
		xe=x2;
	}
	else if(dx<0){
		x=x2;
		y=y2;
		xe=x1;
	}
	c=y-m*x;
	while(x<=xe){
		putpixel(x,y,GREEN);
		x=x+1;
		y=m*x+c;
	}
	getch();
	closegraph();
	return 0;
}
