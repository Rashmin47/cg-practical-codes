#include <stdio.h>
#include <graphics.h>
#include <math.h>
#include<conio.h>
int main() {
    int gd = DETECT, gm;
    int x1 = 8, y1 = 12;
    int x2 = 18, y2 = 20;
    int dx, dy, p, x, y, i;

    initgraph(&gd, &gm, "C:\\TC\\BGI");

    dx = abs(x2 - x1);   // 10
    dy = abs(y2 - y1);   // 8

    x = x1;
    y = y1;

    // Since dx > dy → slope < 1
    p = 2 * dy - dx;   // p = 2*8 - 10 = 6

    for (i = 0; i <= dx; i++) {
	putpixel(x, y, WHITE);

	if (p < 0) {
	    x = x + 1;
	    p = p + 2 * dy;
	} else {
	    x = x + 1;
	    y = y + 1;
	    p = p + 2 * dy - 2 * dx;
	}
    }
    getch();
    closegraph();
    return 0;
}