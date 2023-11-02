#include <stdio.h>
#include <graphics.h>

void liang_barsky() {
    double x1, y1, x2, y2, xmin, ymin, xmax, ymax;

    printf("Enter the coordinates of the first point (x1, y1): ");
    scanf("%lf %lf", &x1, &y1);
    printf("Enter the coordinates of the second point (x2, y2): ");
    scanf("%lf %lf", &x2, &y2);
    printf("Enter the coordinates of the bottom left corner of the clipping window (xmin, ymin): ");
    scanf("%lf %lf", &xmin, &ymin);
    printf("Enter the coordinates of the top right corner of the clipping window (xmax, ymax): ");
    scanf("%lf %lf", &xmax, &ymax);

    initwindow(1000, 1000, "Liang-Barsky");
    rectangle(xmin, ymin, xmax, ymax);
    line(x1, y1, x2, y2);
    getch();
    
    double dx = x2 - x1, dy = y2 - y1, r1 = 0, r2 = 1;
    double p[4] = {-dx, dx, -dy, dy}, q[4] = {x1 - xmin, xmax - x1, y1 - ymin, ymax - y1};

    for(int i = 0; i < 4; i++) {
        if(p[i] == 0 && q[i] < 0) return;
        double r = q[i] / p[i];
        if(p[i] < 0 && r > r1) r1 = r;
        else if(p[i] > 0 && r < r2) r2 = r;
    }

    if(r1 < r2) {
        double nx1 = x1 + r1 * dx, ny1 = y1 + r1 * dy, nx2 = x1 + r2 * dx, ny2 = y1 + r2 * dy;
        cleardevice();
        rectangle(xmin, ymin, xmax, ymax);
        line(nx1, ny1, nx2, ny2);
    }

    getch();
    closegraph();
}

int main() {
    liang_barsky();
    return 0;
}