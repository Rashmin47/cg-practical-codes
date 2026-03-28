#include <stdio.h>
#include <graphics.h>
#include <conio.h>

void perspective(int x, int y, int z, int d)
{
    float xp, yp;

    // Prevent invalid projection
    if (z <= 0)
    {
        printf("Z must be greater than 0 (point should be in front of viewer)");
        return;
    }

    // Perspective projection with scaling
    xp = ((float)x * d) / z;
    yp = ((float)y * d) / z;

    // Scale for better visibility
    xp = xp * 2;
    yp = yp * 2;

    // Draw a visible point (circle instead of pixel)
    circle(320 + xp, 240 - yp, 4);

    // Draw axis reference (optional but helpful)
    line(0, 240, 640, 240);   // X-axis
    line(320, 0, 320, 480);   // Y-axis
}

int main()
{
    int gd = DETECT, gm;
    int x, y, z, d;

    initgraph(&gd, &gm, "C:\\TC\\BGI");

    printf("Enter 3D point (x y z): ");
    scanf("%d %d %d", &x, &y, &z);

    printf("Enter projection distance (d): ");
    scanf("%d", &d);

    perspective(x, y, z, d);

    getch();
    closegraph();
    return 0;
}