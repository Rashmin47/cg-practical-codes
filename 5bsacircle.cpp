#include <stdio.h>
#include<conio.h>
#include <graphics.h>

void drawCircle(int xc, int yc, int x, int y) {
    // Plot all 8 symmetric points
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
    int x = 0, y, p;

    // Input center and radius
    printf("Enter center (xc, yc): ");
    scanf("%d %d", &xc, &yc);

    printf("Enter radius: ");
    scanf("%d", &r);

    initgraph(&gd, &gm, "C:\\TC\\BGI");

    y = r;
    p = 3 - 2 * r;   // Initial decision parameter

    while (x <= y) {
        drawCircle(xc, yc, x, y);

        if (p < 0) {
            p = p + 4 * x + 6;
        } else {
            p = p + 4 * (x - y) + 10;
            y--;
        }
        x++;
    }

    getch();
    closegraph();
    return 0;
}