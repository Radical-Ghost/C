#include <stdio.h>
#include <graphics.h>

void drawQuadraticBezierCurve(int x0, int y0, int x1, int y1, int x2, int y2, int x3, int y3) {
    int t;
    float x, y;

    for (t = 0; t <= 1000; t++) {
        float tN = t / 1000.0;
        x = (1 - tN) * (1 - tN) * (1 - tN) * x0 + 3 * (1 - tN) * (1 - tN) * tN * x1 + 3 * (1 - tN) * tN * tN * x2 + tN * tN * tN * x3;
        y = (1 - tN) * (1 - tN) * (1 - tN) * y0 + 3 * (1 - tN) * (1 - tN) * tN * y1 + 3 * (1 - tN) * tN * tN * y2 + tN * tN * tN * y3;
        //tN is a normalised    
        putpixel(x, y, WHITE);
    }
}

int main() {
    int width = GetSystemMetrics(SM_CXSCREEN), height = GetSystemMetrics(SM_CYSCREEN);
	initwindow(width, height, (char*)"", -3, -3);

    int x0, y0, x1, y1, x2, y2, x3, y3;

    printf("Enter the coordinates of the control points:\n");
    printf("Point 1 (x0, y0): ");
    scanf("%d %d", &x0, &y0);
    printf("Point 2 (x1, y1): ");
    scanf("%d %d", &x1, &y1);
    printf("Point 3 (x2, y2): ");
    scanf("%d %d", &x2, &y2);
    printf("Point 4 (x3, y3): ");
    scanf("%d %d", &x3, &y3);

    drawQuadraticBezierCurve(x0, y0, x1, y1, x2, y2, x3, y3);

    delay(5000);
    closegraph();

    return 0;
}
