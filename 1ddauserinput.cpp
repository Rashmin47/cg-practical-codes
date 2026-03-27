#include <stdio.h>
#include<conio.h>
#include <graphics.h>
#include <math.h>

int main() {
    int gd = DETECT, gm;
    float x1, y1, x2, y2;
    float dx, dy, steps, x_inc, y_inc, x, y;
    int i;

    // Input endpoints
    printf("Enter x1 and y1: ");
    scanf("%f %f", &x1, &y1);

    printf("Enter x2 and y2: ");
    scanf("%f %f", &x2, &y2);

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

    // Plotting the line using DDA
    for (i = 0; i <= steps; i++) {
        putpixel(round(x), round(y), WHITE);
        x += x_inc;
        y += y_inc;
    }

    getch();
    closegraph();
    return 0;
}