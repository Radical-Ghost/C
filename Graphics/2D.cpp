#include <stdio.h>
#include <graphics.h>
#include <math.h>

int x[3], y[3];

void input_co() {
 	printf("Enter the coordinates of the triangle:\n");
    for(int i = 0; i < 3; i++) {
        printf("(x%d, y%d): ", i, i);
        scanf("%d %d", &x[i], &y[i]);
    }
}

void drawTriangle(int x0, int y0, int x1, int y1, int x2, int y2) {
	line(x0, y0, x1, y1);
	line(x1, y1, x2, y2);
	line(x2, y2, x0, y0);
}

void translation() {
	input_co();
	drawTriangle(x[0], y[0], x[1], y[1], x[2], y[2]);

	int tx, ty;
	printf("Enter the translation factor: ");
	scanf("%d %d", &tx, &ty);

	for(int i = 0; i < 3; i++) {
		x[i] += tx;
		y[i] += ty;
	}
	drawTriangle(x[0], y[0], x[1], y[1], x[2], y[2]);
}

void scaling() {
	input_co();
	drawTriangle(x[0], y[0], x[1], y[1], x[2], y[2]);

	int sx, sy;
	printf("Enter the scaling factor: ");
	scanf("%d %d", &sx, &sy);

	for(int i = 0; i < 3; i++) {
		x[i] *= sx;
		y[i] *= sy;
	}

	drawTriangle(x[0], y[0], x[1], y[1], x[2], y[2]);
}

void rotation() {
    input_co();
    drawTriangle(x[0], y[0], x[1], y[1], x[2], y[2]);

    int angle;
    printf("Enter the angle of rotation (in degrees): ");
    scanf("%d", &angle);

    double radian = angle * 3.14 / 180;
    for(int i = 0; i < 3; i++) {
        int temp_x = x[i], temp_y = y[i];
        x[i] = temp_x*cos(radian) - temp_y*sin(radian);
        y[i] = temp_x*sin(radian) + temp_y*cos(radian);
    }

    drawTriangle(x[0], y[0], x[1], y[1], x[2], y[2]);
}

int main() {
	int c = 0;
	int height = GetSystemMetrics(SM_CYSCREEN), width = GetSystemMetrics(SM_CXSCREEN);
	initwindow(width, height, (char*)"2D Transformations", -3, -5);

	do{
		cleardevice();
		printf("1. Translation\n2. Scaling\n3. Rotation\n4. Exit\nEnter your choice:");
		scanf("%d", &c);
		switch(c){
			case 1:
				translation();
				break;
			
			case 2:
				scaling();
				break;
			
			case 3:
				rotation();
				break;
			
			case 4:
				exit(0);
			
			default:
				printf("Invalid choice\n");
		}
		getch();
	}while(c != 4);

	closegraph();
	return 0;
}
