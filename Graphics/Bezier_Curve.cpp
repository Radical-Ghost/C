#include <stdio.h>
#include <graphics.h>

void drawQuadraticBezierCurve(int x[4], int y[4]) {
    int t;
    float xt, yt;

    for (t = 0; t <= 1000; t++) {
        float tN = t / 1000.0;
        xt = (1 - tN) * (1 - tN) * (1 - tN) * x[0] + 3 * (1 - tN) * (1 - tN) * tN * x[1] + 3 * (1 - tN) * tN * tN * x[2] + tN * tN * tN * x[3];
        yt = (1 - tN) * (1 - tN) * (1 - tN) * y[0] + 3 * (1 - tN) * (1 - tN) * tN * y[1] + 3 * (1 - tN) * tN * tN * y[2] + tN * tN * tN * y[3];
        putpixel(xt, yt, WHITE);
    }

    for (int i = 0; i < 4; i++)
        putpixel(x[i], y[i], YELLOW);
}

int main() {
    int width = GetSystemMetrics(SM_CXSCREEN), height = GetSystemMetrics(SM_CYSCREEN);
    initwindow(width, height, (char*)"", -3, -3);

    int x[4], y[4];

    printf("Enter the coordinates of the control points:\n");
    for(int i = 0; i < 4; i++) {
        printf("Point %d (x%d, y%d): ", i+1, i, i);
        scanf("%d %d", &x[i], &y[i]);
    }

    drawQuadraticBezierCurve(x, y);

    delay(5000);
    closegraph();

    return 0;
}