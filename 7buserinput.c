#include <stdio.h>
#include <conio.h>
#include <graphics.h>
#include <math.h>

int main() {
    int gd = DETECT, gm;
    float x1, y1, x2, y2;
    float x1_new, y1_new, x2_new, y2_new;
    float angle;

    // Input endpoints
    printf("Enter x1 y1: ");
    scanf("%f %f", &x1, &y1);

    printf("Enter x2 y2: ");
    scanf("%f %f", &x2, &y2);

    // Convert 30 degrees to radians
    angle = 30 * 3.14 / 180;

    initgraph(&gd, &gm, "C:\\TC3\\BGI");

    // Draw original line
    setcolor(WHITE);
    line(x1, y1, x2, y2);

    // Anti-clockwise rotation
    x1_new = x1 * cos(angle) - y1 * sin(angle);
    y1_new = x1 * sin(angle) + y1 * cos(angle);

    x2_new = x2 * cos(angle) - y2 * sin(angle);
    y2_new = x2 * sin(angle) + y2 * cos(angle);

    // Draw rotated line
    setcolor(RED);
    line(x1_new , y1_new , x2_new , y2_new);

    getch();
    closegraph();
    return 0;
}