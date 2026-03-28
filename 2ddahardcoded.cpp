#include <stdio.h>
#include<conio.h>
#include <graphics.h>
#include <math.h>

int main() {
    int gd = DETECT, gm;
    float x1 = 10, y1 = 12;
    float x2 = 15, y2 = 17;
    float dx, dy, steps, x_inc, y_inc, x, y;
    int i;

    // Initialize graphics
    initgraph(&gd, &gm, "C:\\TC\\BGI");

    // Calculate dx and dy
    dx = x2 - x1;
    dy = y2 - y1;

    // Determine number of steps
    if (fabs(dx) > fabs(dy))
        steps = fabs(dx);
    else
        steps = fabs(dy);

    // Calculate increments
    x_inc = dx / steps;
    y_inc = dy / steps;

    // Initial point
    x = x1;
    y = y1;

    // Plotting points
    for (i = 0; i <= steps; i++) {
        putpixel((int)(x + 0.5), (int)(y + 0.5), WHITE);
        x += x_inc;
        y += y_inc;
    }

    getch();
    closegraph();
    return 0;
}