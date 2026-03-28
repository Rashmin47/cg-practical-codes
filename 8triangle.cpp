#include <stdio.h>
#include<conio.h>
#include <graphics.h>

int main() {
    int gd = DETECT, gm;

    // Original triangle
    int x1 = 3, y1 = 4;
    int x2 = 6, y2 = 4;
    int x3 = 4, y3 = 8;

    // Reflected triangle (x-axis)
    int x1r = x1, y1r = -y1;
    int x2r = x2, y2r = -y2;
    int x3r = x3, y3r = -y3;

    int xc = 320, yc = 240;  // Screen center

    initgraph(&gd, &gm, "C:\\TC\\BGI");

    // Draw X and Y axes
    line(0, yc, 640, yc);   // X-axis
    line(xc, 0, xc, 480);   // Y-axis

    // Draw original triangle
    setcolor(WHITE);
    line(xc + x1*20, yc - y1*20, xc + x2*20, yc - y2*20);
    line(xc + x2*20, yc - y2*20, xc + x3*20, yc - y3*20);
    line(xc + x3*20, yc - y3*20, xc + x1*20, yc - y1*20);

    // Draw reflected triangle
    setcolor(RED);
    line(xc + x1r*20, yc - y1r*20, xc + x2r*20, yc - y2r*20);
    line(xc + x2r*20, yc - y2r*20, xc + x3r*20, yc - y3r*20);
    line(xc + x3r*20, yc - y3r*20, xc + x1r*20, yc - y1r*20);

    getch();
    closegraph();
    return 0;
}
