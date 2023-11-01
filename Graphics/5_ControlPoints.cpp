#include <graphics.h>
#include <math.h>

void bezier(int x[5], int y[5]) {
    int width = GetSystemMetrics(SM_CXSCREEN), height = GetSystemMetrics(SM_CYSCREEN);
	initwindow(width, height, (char*)"", -3, -3);

    double t;
    for (t = 0.0; t < 1.0; t += 0.0005) {
        double xt = pow(1 - t, 4) * x[0] + 4 * pow(1 - t, 3) * t * x[1] + 6 * pow(1 - t, 2) * t * t * x[2] + 4 * (1 - t) * pow(t, 3) * x[3] + pow(t, 4) * x[4];
        double yt = pow(1 - t, 4) * y[0] + 4 * pow(1 - t, 3) * t * y[1] + 6 * pow(1 - t, 2) * t * t * y[2] + 4 * (1 - t) * pow(t, 3) * y[3] + pow(t, 4) * y[4];
        putpixel(xt, yt, WHITE);

    }

    for (int i = 0; i < 5; i++)
        putpixel(x[i], y[i], YELLOW);

    getch();
    closegraph();
}

int main() {
    int x[5], y[5];
    printf("Enter the x and y coordinates of the five control points: ");
    for (int i = 0; i < 5; i++)
        scanf("%d%d", &x[i], &y[i]);

    bezier(x, y);
    return 0;
}