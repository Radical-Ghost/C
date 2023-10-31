#include <stdio.h>
#include <graphics.h>

void drawQuadraticBezierCurve(int x0, int y0, int x1, int y1, int x2, int y2) {
    int t;
    float x, y;

    for (t = 0; t <= 1000; t++) {
        float tNormalized = t / 1000.0;
        x = (1 - tNormalized) * (1 - tNormalized) * x0 + 2 * (1 - tNormalized) * tNormalized * x1 + tNormalized * tNormalized * x2;
        y = (1 - tNormalized) * (1 - tNormalized) * y0 + 2 * (1 - tNormalized) * tNormalized * y1 + tNormalized * tNormalized * y2;

        putpixel(x, y, WHITE); // You might need to replace WHITE with your preferred color.
    }
}

int main() {
    int width = GetSystemMetrics(SM_CXSCREEN), height = GetSystemMetrics(SM_CYSCREEN);
	initwindow(width, height, (char*)"", -3, -3);

    int x0, y0, x1, y1, x2, y2;

    printf("Enter the coordinates of the control points:\n");
    printf("Point 1 (x0, y0): ");
    scanf("%d %d", &x0, &y0);
    printf("Point 2 (x1, y1): ");
    scanf("%d %d", &x1, &y1);
    printf("Point 3 (x2, y2): ");
    scanf("%d %d", &x2, &y2);

    drawQuadraticBezierCurve(x0, y0, x1, y1, x2, y2);

    delay(5000); // Display the curve for a few seconds before closing the window.
    closegraph();

    return 0;
}
