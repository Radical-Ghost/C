#include<stdio.h>
#include<conio.h>
#include<graphics.h>

void boundary_fill(int x,int y,int f_color,int b_color){

	if (getpixel(x,y)!=b_color && getpixel(x,y)!= f_color) {
		putpixel(x,y,f_color);
		boundary_fill(x+1,y,f_color,b_color);
		boundary_fill(x,y+1,f_color,b_color);
		boundary_fill(x-1,y,f_color,b_color);
		boundary_fill(x,y-1,f_color,b_color);
	}
}

void flood_fill(int x,int y,int old_color,int f_color){

	if (getpixel(x,y) == old_color) {
		putpixel(x,y,f_color);
		flood_fill(x+1,y,old_color,f_color);
		flood_fill(x,y+1,old_color,f_color);
		flood_fill(x-1,y,old_color,f_color);
		flood_fill(x,y-1,old_color,f_color);
	}
}

int main(){
	int x,y;

	printf("Enter seed point within (1 - 100): ");
	scanf("%d%d",&x,&y);

	int width = GetSystemMetrics(SM_CXSCREEN), height = GetSystemMetrics(SM_CYSCREEN);
	initwindow(width, height, (char*)"", -3, -3);

	rectangle(300, 500, 500, 700);
	rectangle(800, 500, 1000, 700);
	boundary_fill(300+x, 500+y, 11, 15);
	flood_fill(800+x, 500+y, 0, 9);

	getch();
	closegraph();
}