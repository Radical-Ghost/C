#include <stdio.h>
#include <conio.h>
#include <graphics.h>

void Circle(int xc, int yc, int r) {
	int x=0, y=r, po= 1-r;
	int width = GetSystemMetrics(SM_CXSCREEN), height = GetSystemMetrics(SM_CYSCREEN);
	initwindow(width, height, (char*)"", -3, -3);


	while(x<y) {
        putpixel(xc+x, yc+y, 11);
        putpixel(xc-x, yc+y, 11);
        putpixel(xc+x, yc-y, 11);
        putpixel(xc-x, yc-y, 11);
        putpixel(xc+y, yc+x, 11);
        putpixel(xc+y, yc-x, 11);
        putpixel(xc-y, yc+x, 11);
        putpixel(xc-y, yc-x, 11);
        delay(10);

		if(po<0) {
			x++;
			po= po + 2*x + 1;
		}
		else {
			x++;
			y--;
			po= po + 2*(x-y) + 1;
		}
	}

	getch();
	closegraph();
}

int main(){
    int xc,yc,r;
    printf("Enter Centre: ");
    scanf("%d %d", &xc, &yc);
    printf("Enter Radius: ");
    scanf("%d", &r);
    Circle(xc, yc, r);
}