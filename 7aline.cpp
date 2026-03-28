#include <stdio.h>
#include <conio.h>
#include <graphics.h>
#include <math.h>

int main() {
    int gd = DETECT, gm;

    float x1 = 2, y1 = 5;
    float x2 = 6, y2 = 12;

    float angle = 30 * 3.14 / 180; // Convert to radians

    float x1_new, y1_new, x2_new, y2_new;

    initgraph(&gd, &gm, "C:\\TC\\BGI");

    // Draw original line
    setcolor(WHITE);
    line(x1*20, y1*20, x2*20, y2*20);

    // Rotation (clockwise)
    x1_new = x1 * cos(angle) + y1 * sin(angle);
    y1_new = -x1 * sin(angle) + y1 * cos(angle);

    x2_new = x2 * cos(angle) + y2 * sin(angle);
    y2_new = -x2 * sin(angle) + y2 * cos(angle);

    // Draw rotated line
    setcolor(RED);
    line(x1_new*20, y1_new*20, x2_new*20, y2_new*20);

    getch();
    closegraph();
    return 0;
}