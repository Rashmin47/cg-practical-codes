#include <stdio.h>
#include <conio.h>
#include <graphics.h>

float max(float a, float b) {
    return (a > b) ? a : b;
}

float min(float a, float b) {
    return (a < b) ? a : b;
}

int main() {
    int gd = DETECT, gm;

    float x1, y1, x2, y2;
    float xmin, ymin, xmax, ymax;
    float dx, dy, p[4], q[4];
    float t1 = 0.0, t2 = 1.0, temp;
    int i;

    // Input line endpoints
    printf("Enter x1 y1: ");
    scanf("%f %f", &x1, &y1);

    printf("Enter x2 y2: ");
    scanf("%f %f", &x2, &y2);

    // Input clipping window
    printf("Enter xmin ymin xmax ymax: ");
    scanf("%f %f %f %f", &xmin, &ymin, &xmax, &ymax);

    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

    // Draw original line
    line(x1, y1, x2, y2);

    dx = x2 - x1;
    dy = y2 - y1;

    // Define p and q
    p[0] = -dx; q[0] = x1 - xmin;
    p[1] = dx;  q[1] = xmax - x1;
    p[2] = -dy; q[2] = y1 - ymin;
    p[3] = dy;  q[3] = ymax - y1;

    for (i = 0; i < 4; i++) {
        if (p[i] == 0) {
            if (q[i] < 0) {
                printf("Line is outside the clipping window\n");
                getch();
                closegraph();
                return 0;
            }
        } else {
            temp = q[i] / p[i];

            if (p[i] < 0)
                t1 = max(t1, temp);
            else
                t2 = min(t2, temp);
        }
    }

    if (t1 < t2) {
        float xc1 = x1 + t1 * dx;
        float yc1 = y1 + t1 * dy;
        float xc2 = x1 + t2 * dx;
        float yc2 = y1 + t2 * dy;

        // Draw clipping window
        rectangle(xmin, ymin, xmax, ymax);

        // Draw clipped line
        setcolor(RED);
        line(xc1, yc1, xc2, yc2);
    } else {
        printf("Line is outside the clipping window\n");
    }

    getch();
    closegraph();
    return 0;
}