#include<conio.h>
#include<graphics.h>

int main() {
	int gd=DETECT,gm;
	char path[]= "c:\\tc\\bgi";

	initgraph(&gd,&gm,path);

	circle(150,150,100);
	circle(100,100,30);
	circle(200,100,30);
	arc(150,150,230,330,50);

	getch();
	closegraph();
}