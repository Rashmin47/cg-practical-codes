#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<math.h>

int main()
{
    int gd=DETECT,gm;
    initgraph(&gd,&gm,"C:\\TC\\BGI");

    float x1,y1,x2,y2,x3,y3;
    float xr1,yr1,xr2,yr2,xr3,yr3;
    float angle;

    int xc = 320, yc = 240;
    int scale = 40;     // increased scale
    int offset = 180;   // spacing between shapes

    // Input
    printf("Enter A: ");
    scanf("%f%f",&x1,&y1);

    printf("Enter B: ");
    scanf("%f%f",&x2,&y2);

    printf("Enter C: ");
    scanf("%f%f",&x3,&y3);

    printf("Enter angle: ");
    scanf("%f",&angle);

    angle = angle * 3.14 / 180;

    // ---------- ORIGINAL ----------
    setcolor(WHITE);
    line(xc - offset + x1*scale, yc - y1*scale,
         xc - offset + x2*scale, yc - y2*scale);

    line(xc - offset + x2*scale, yc - y2*scale,
         xc - offset + x3*scale, yc - y3*scale);

    line(xc - offset + x3*scale, yc - y3*scale,
         xc - offset + x1*scale, yc - y1*scale);

    // ---------- ROTATION ----------
    xr1 = x1*cos(angle) - y1*sin(angle);
    yr1 = x1*sin(angle) + y1*cos(angle);

    xr2 = x2*cos(angle) - y2*sin(angle);
    yr2 = x2*sin(angle) + y2*cos(angle);

    xr3 = x3*cos(angle) - y3*sin(angle);
    yr3 = x3*sin(angle) + y3*cos(angle);

    // ---------- ROTATED ----------
    setcolor(RED);
    line(xc + offset + xr1*scale, yc - yr1*scale,
         xc + offset + xr2*scale, yc - yr2*scale);

    line(xc + offset + xr2*scale, yc - yr2*scale,
         xc + offset + xr3*scale, yc - yr3*scale);

    line(xc + offset + xr3*scale, yc - yr3*scale,
         xc + offset + xr1*scale, yc - yr1*scale);

   
    getch();
    closegraph();
    return 0;
}