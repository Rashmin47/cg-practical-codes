#include <stdio.h>
#include <conio.h>
#include <graphics.h>

#define INSIDE 0 // 0000
#define LEFT   1 // 0001
#define RIGHT  2 // 0010
#define BOTTOM 4 // 0100
#define TOP    8 // 1000

int xmin, ymin, xmax, ymax;

// Function to compute region code for a point (x, y)
int computeCode(int x, int y) {
    int code = INSIDE;

    if (x < xmin) code |= LEFT;
    else if (x > xmax) code |= RIGHT;

    if (y < ymin) code |= BOTTOM;
    else if (y > ymax) code |= TOP;

    return code;
}

// Cohen-Sutherland clipping algorithm
void cohenSutherlandClip(int x1, int y1, int x2, int y2) {
    int code1 = computeCode(x1, y1);
    int code2 = computeCode(x2, y2);
    int accept = 0;

    while (1) {
        if ((code1 == 0) && (code2 == 0)) {
            // Both endpoints inside: accept line
            accept = 1;
            break;
        } else if (code1 & code2) {
            // Logical AND != 0: trivially reject
            break;
        } else {
            int x, y;
            int code_out = code1 ? code1 : code2;

            if (code_out & TOP) {
                x = x1 + (x2 - x1) * (ymax - y1) / (y2 - y1);
                y = ymax;
            } else if (code_out & BOTTOM) {
                x = x1 + (x2 - x1) * (ymin - y1) / (y2 - y1);
                y = ymin;
            } else if (code_out & RIGHT) {
                y = y1 + (y2 - y1) * (xmax - x1) / (x2 - x1);
                x = xmax;
            } else if (code_out & LEFT) {
                y = y1 + (y2 - y1) * (xmin - x1) / (x2 - x1);
                x = xmin;
            }

            if (code_out == code1) {
                x1 = x;
                y1 = y;
                code1 = computeCode(x1, y1);
            } else {
                x2 = x;
                y2 = y;
                code2 = computeCode(x2, y2);
            }
        }
    }

    // Draw
    if (accept) {
        setcolor(RED);
        line(x1, y1, x2, y2);
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\TC\\BGI");

    int x1, y1, x2, y2;

    printf("Enter clipping window (xmin ymin xmax ymax): ");
    scanf("%d%d%d%d", &xmin, &ymin, &xmax, &ymax);

    // Draw clipping rectangle
    rectangle(xmin, ymin, xmax, ymax);

    printf("Enter line coordinates (x1 y1 x2 y2): ");
    scanf("%d%d%d%d", &x1, &y1, &x2, &y2);

    // Draw original line in WHITE
    setcolor(WHITE);
    line(x1, y1, x2, y2);

    getch(); // wait to see original line

    cleardevice();
    // Draw clipping rectangle again
    rectangle(xmin, ymin, xmax, ymax);

    // Perform clipping
    cohenSutherlandClip(x1, y1, x2, y2);

    getch();
    closegraph();
    return 0;
}