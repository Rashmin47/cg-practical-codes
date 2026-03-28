#include <graphics.h>
#include <conio.h>
#include <math.h>
#include <stdio.h>

#define D2R 0.0174533   // Degree to radian

// Function to draw line after projection
void drawLine(int x1, int y1, int x2, int y2)
{
    line(320 + x1, 240 - y1, 320 + x2, 240 - y2);
}

// Parallel Projection Function (Oblique)
void project(int x, int y, int z, int *xp, int *yp)
{
    float l = 0.5;      // projection length
    float angle = 45;   // projection angle

    *xp = x + l * z * cos(angle * D2R);
    *yp = y + l * z * sin(angle * D2R);
}

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\TC\\BGI");

    // Cube vertices (x, y, z)
    int x[8] = {50, 150, 150, 50, 50, 150, 150, 50};
    int y[8] = {50, 50, 150, 150, 50, 50, 150, 150};
    int z[8] = {50, 50, 50, 50, 150, 150, 150, 150};

    int xp[8], yp[8];
    int i;

    // Project all points
    for (i = 0; i < 8; i++)
    {
        project(x[i], y[i], z[i], &xp[i], &yp[i]);
    }

    // Draw front face
    drawLine(xp[0], yp[0], xp[1], yp[1]);
    drawLine(xp[1], yp[1], xp[2], yp[2]);
    drawLine(xp[2], yp[2], xp[3], yp[3]);
    drawLine(xp[3], yp[3], xp[0], yp[0]);

    // Draw back face
    drawLine(xp[4], yp[4], xp[5], yp[5]);
    drawLine(xp[5], yp[5], xp[6], yp[6]);
    drawLine(xp[6], yp[6], xp[7], yp[7]);
    drawLine(xp[7], yp[7], xp[4], yp[4]);

    // Connect front & back
    for (i = 0; i < 4; i++)
    {
        drawLine(xp[i], yp[i], xp[i + 4], yp[i + 4]);
    }

    outtextxy(200, 20, "Parallel Projection of Cube");

    getch();
    closegraph();
    return 0;
}