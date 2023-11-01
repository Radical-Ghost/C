#include <stdio.h>
#include <conio.h> 
#include <graphics.h>  

void BSH(int x1, int y1, int x2, int y2) {
	int gd=DETECT, gm;
	initgraph(&gd, &gm, (char*)"");

	int dx=x2-x1;
	int dy=y2-y1;

	int p= 2*dy-dx;
	for(int i = 0; i < dx; i++) {
		if(p < 0) {
			putpixel(x1++,y1,15);
			p=p+2*dy;
		}
		else {
			putpixel(x1++,y1++,15);
			p=p+2*(dy-dx);
		}
		delay(10);
	}

	getch();
	closegraph();
}

int main(){
    int x1, y1, x2, y2;
    printf("Enter the starting coordinates : ");
    scanf("%d %d", &x1, &y1);
    printf("Enter the ending coordinates : ");
    scanf("%d %d", &x2, &y2);
    BSH(x1, y1, x2, y2);
}