#include <stdio.h>
#include<conio.h>
#include <graphics.h>
#include <math.h>

int main() {
    int gd = DETECT, gm;
    int x1, y1, x2, y2;
    int dx, dy, p, x, y, i;

    // Input endpoints
    printf("Enter x1 and y1: ");
    scanf("%d %d", &x1, &y1);

    printf("Enter x2 and y2: ");
    scanf("%d %d", &x2, &y2);

    // Initialize graphics
    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

    dx = abs(x2 - x1);
    dy = abs(y2 - y1);

    x = x1;
    y = y1;

    // For slope < 1
    if (dx >= dy) {
        p = 2 * dy - dx;

        for (i = 0; i <= dx; i++) {
            putpixel(x, y, WHITE);

            if (p < 0) {
                x = (x < x2) ? x + 1 : x - 1;
                p = p + 2 * dy;
            } else {
                x = (x < x2) ? x + 1 : x - 1;
                y = (y < y2) ? y + 1 : y - 1;
                p = p + 2 * dy - 2 * dx;
            }
        }
    }
    // For slope >= 1
    else {
        p = 2 * dx - dy;

        for (i = 0; i <= dy; i++) {
            putpixel(x, y, WHITE);

            if (p < 0) {
                y = (y < y2) ? y + 1 : y - 1;
                p = p + 2 * dx;
            } else {
                x = (x < x2) ? x + 1 : x - 1;
                y = (y < y2) ? y + 1 : y - 1;
                p = p + 2 * dx - 2 * dy;
            }
        }
    }

    getch();
    closegraph();
    return 0;
}