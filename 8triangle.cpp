#include <stdio.h>
#include <conio.h>
#include <graphics.h>

int main() {
    int gd = DETECT, gm;

    // Original coordinates
    int x1 = 3, y1 = 4;
    int x2 = 6, y2 = 4;
    int x3 = 4, y3 = 8;

    // Reflected coordinates (x-axis)
    int x1r = x1, y1r = -y1;
    int x2r = x2, y2r = -y2;
    int x3r = x3, y3r = -y3;

    initgraph(&gd, &gm, "C:\\TC\\BGI");

    // Draw original triangle
    setcolor(WHITE);
    line(x1*20, y1*20, x2*20, y2*20);
    line(x2*20, y2*20, x3*20, y3*20);
    line(x3*20, y3*20, x1*20, y1*20);

    // Draw reflected triangle
    setcolor(RED);
    line(x1r*20, y1r*20, x2r*20, y2r*20);
    line(x2r*20, y2r*20, x3r*20, y3r*20);
    line(x3r*20, y3r*20, x1r*20, y1r*20);

    getch();
    closegraph();
    return 0;
}