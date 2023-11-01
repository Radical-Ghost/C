#include<conio.h>
#include<graphics.h>
#include<math.h>

void Ellipse(int xc, int yc, int rx, int ry) {
    int x = 0, y = ry;
    float dx = (float)(2*ry*ry*x), dy = (float)(2*rx*rx*y);
    float p1 = (float)(ry*ry - (rx*rx*ry) + (0.25*rx*rx));
    int width = GetSystemMetrics(SM_CXSCREEN), height = GetSystemMetrics(SM_CYSCREEN);
    initwindow(width, height, (char*)"", -3, -3);

    while(dx < dy) {
        putpixel(xc+x, yc+y, 15);
        putpixel(xc-x, yc+y, 15);
        putpixel(xc+x, yc-y, 15);
        putpixel(xc-x, yc-y, 15);
        delay(100);

        if(p1 < 0) {
            x++;
            dx += (2*ry*ry);
            p1 += + dx + (ry*ry);
        }
        else {
            x++; y--;
            dx += (2*ry*ry);
            dy -= (2*rx*rx);
            p1 += dx - dy + (ry*ry);
        }
    }

    float p2 = (float)(((ry*ry)*(x+0.5)*(x+0.5)) + ((rx*rx)*(y-1)*(y-1)) - (rx*rx*ry*ry));

    while(y >= 0) {
        putpixel(xc+x, yc+y, 15);
        putpixel(xc-x, yc+y, 15);
        putpixel(xc+x, yc-y, 15);
        putpixel(xc-x, yc-y, 15);
        delay(100);

        if(p2 > 0) {
            y--;
            dy -= (2*rx*rx);
            p2 += (rx*rx) - dy;
        }
        else {
            y--; x++;
            dx += (2*ry*ry);
            dy -= (2*rx*rx);
            p2 += dx - dy + (rx*rx);
        }
    }

    getch();
    closegraph();
}

int main() {
    int xc, yc, rx, ry;
    printf("Enter the center coordinates : ");
	scanf("%d %d", &xc, &yc);
	printf("Enter the radius along x-axis : ");
    scanf("%d", &rx);
    printf("Enter the radius along y-axis : ");
    scanf("%d", &ry);
    Ellipse(xc, yc, rx, ry);
    return 0;
}