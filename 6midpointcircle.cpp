#include <stdio.h>
#include <conio.h>
#include <graphics.h>

void plotPoints(int xc, int yc, int x, int y) {
    // 8-way symmetry
    putpixel(xc + x, yc + y, WHITE);
    putpixel(xc - x, yc + y, WHITE);
    putpixel(xc + x, yc - y, WHITE);
    putpixel(xc - x, yc - y, WHITE);
    putpixel(xc + y, yc + x, WHITE);
    putpixel(xc - y, yc + x, WHITE);
    putpixel(xc + y, yc - x, WHITE);
    putpixel(xc - y, yc - x, WHITE);
}

int main() {
    int gd = DETECT, gm;
    int xc, yc, r;
    int x = 0, y;
    int p;

    // Input
    printf("Enter center (xc, yc): ");
    scanf("%d %d", &xc, &yc);

    printf("Enter radius: ");
    scanf("%d", &r);

    initgraph(&gd, &gm, "C:\\TC\\BGI");

    y = r;
    p = 1 - r;   // Initial decision parameter

    while (x <= y) {
        plotPoints(xc, yc, x, y);

        if (p < 0) {
            p = p + 2 * x + 3;
        } else {
            p = p + 2 * (x - y) + 5;
            y--;
        }
        x++;
    }

    getch();
    closegraph();
    return 0;
}