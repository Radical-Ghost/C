#include<iostream>
#include<conio.h>
#include<graphics.h>
#include<math.h>

void Circle(int xc, int yc, int r) {
	int x=0, y=r;
	int p= 1-r;
	int width = GetSystemMetrics(SM_CXSCREEN), height = GetSystemMetrics(SM_CYSCREEN);
	initwindow(width, height, (char*)"", -3, -3);


	while(x<y) {
	putpixel(xc+x, yc+y, 15);
	putpixel(xc-x, yc+y, 15);
	putpixel(xc+x, yc-y, 15);
	putpixel(xc-x, yc-y, 15);
	putpixel(xc+y, yc+x, 15);
	putpixel(xc+y, yc-x, 15);
	putpixel(xc-y, yc+x, 15);
	putpixel(xc-y, yc-x, 15);
	delay(100);

		if(p < 0) {
			x++;
			p= p + 2*x + 1;
		}
		else {
			x++;
			y--;
			p = p + 2*(x-y) + 1;
		}
	}

	getch();
	closegraph();
}

int main() {
	int xc,yc,r;
	printf("Enter the center coordinates : ");
	scanf("%d %d", &xc, &yc);
	printf("Enter the radius : ");
	scanf("%d", &r);
	Circle(xc, yc, r);
	return 0;
}