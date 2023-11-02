#include <stdio.h>
#include <graphics.h>

int points[80][2] = { { 0 } }; 
int news[80][2] = { { 0 } };

int leftClip(int, int);
int topClip(int, int);
int rightClip(int, int);
int bottomClip(int, int);

int main() {
	int width = GetSystemMetrics(SM_CXSCREEN), height = GetSystemMetrics(SM_CYSCREEN), xmin, ymir, xmax, ymax, n, i;
	printf(
			"Enter the co-ordinates of top left corner of the clipping window: ");
	scanf("%d %d", &xmin, &ymir);
	printf(
			"Enter the co-ordinates of bottom right corner of the clipping window: ");
	scanf("%d %d", &xmax, &ymax);

	printf("Enter the number of co-ordinates of the polygon: ");
	scanf("%d", &n);

	for (i = 0; i < n; i++) {
		printf("Enter the co-ordinates of vertex %d: ", (i + 1));
		scanf("%d %d", &points[i][0], &points[i][1]);
	}

    initwindow(width, height, (char*)"Polygon Clipping", -3, -5);
	rectangle(xmin, ymir, xmax, ymax);
	for (i = 0; i < n; i++)
		line(points[i][0], points[i][1], points[(i + 1) % n][0],
				points[(i + 1) % n][1]);

	int result = leftClip(n, xmin);
	result = topClip(result, ymir);
	result = rightClip(result, xmax);
	result = bottomClip(result, ymax);

	delay(3000);
	cleardevice();
	rectangle(xmin, ymir, xmax, ymax);
	for (i = 0; i < result; i++)
		line(points[i][0], points[i][1], points[(i + 1) % result][0],
				points[(i + 1) % result][1]);
    getch();
    closegraph();
	return 0;
}

int leftClip(int limit, int xmin) {
	int i, j = 0, x1, y1, x2, y2;
	float m;
	for (i = 0; i < limit; i++) {
		x1 = points[i][0];
		y1 = points[i][1];
		x2 = points[(i + 1) % limit][0];
		y2 = points[(i + 1) % limit][1];
		if (x2 - x1)
			m = (y2 - y1) * 1.0 / (x2 - x1);

		if (x1 < xmin && x2 < xmin)
			continue;
		if (x1 > xmin && x2 > xmin) {
			news[j][0] = x2;
			news[j++][1] = y2;
			continue;
		}
		if (x1 > xmin && x2 < xmin) {
			news[j][0] = xmin;
			news[j++][1] = y1 + m * (xmin - x1);
			continue;
		}
		if (x1 < xmin && x2 > xmin) {
			news[j][0] = xmin;
			news[j++][1] = y1 + m * (xmin - x1);
			news[j][0] = x2;
			news[j++][1] = y2;
		}
	}

	for (i = 0; i < j; i++) {
		points[i][0] = news[i][0];
		points[i][1] = news[i][1];
		news[i][0] = news[i][1] = 0;
	}

	if (j < limit)
		for (; i < limit; i++)
			points[i][0] = points[i][1] = 0;

	return j;
}

int topClip(int limit, int ymir) {
	int i, j = 0, x1, y1, x2, y2;
	float m;
	for (i = 0; i < limit; i++) {
		x1 = points[i][0];
		y1 = points[i][1];
		x2 = points[(i + 1) % limit][0];
		y2 = points[(i + 1) % limit][1];
		if (x2 - x1)
			m = (y2 - y1) * 1.0 / (x2 - x1);

		if (y1 < ymir && y2 < ymir)
			continue;
		if (y1 > ymir && y2 > ymir) {
			news[j][0] = x2;
			news[j++][1] = y2;
			continue;
		}
		if (y1 > ymir && y2 < ymir) {
			news[j][0] = x1 + (ymir - y1) / m;
			news[j++][1] = ymir;
			continue;
		}
		if (y1 < ymir && y2 > ymir) {
			news[j][0] = x1 + (ymir - y1) / m;
			news[j++][1] = ymir;
			news[j][0] = x2;
			news[j++][1] = y2;
		}
	}

	for (i = 0; i < j; i++) {
		points[i][0] = news[i][0];
		points[i][1] = news[i][1];
		news[i][0] = news[i][1] = 0;
	}

	if (j < limit)
		for (; i < limit; i++)
			points[i][0] = points[i][1] = 0;

	return j;
}

int rightClip(int limit, int xmax) {
	int i, j = 0, x1, y1, x2, y2;
	float m;
	for (i = 0; i < limit; i++) {
		x1 = points[i][0];
		y1 = points[i][1];
		x2 = points[(i + 1) % limit][0];
		y2 = points[(i + 1) % limit][1];
		if (x2 - x1)
			m = (y2 - y1) * 1.0 / (x2 - x1);

		if (x1 > xmax && x2 > xmax)
			continue;
		if (x1 < xmax && x2 < xmax) {
			news[j][0] = x2;
			news[j++][1] = y2;
			continue;
		}
		if (x1 < xmax && x2 > xmax) {
			news[j][0] = xmax;
			news[j++][1] = y1 + m * (xmax - x1);
			continue;
		}
		if (x1 > xmax && x2 < xmax) {
			news[j][0] = xmax;
			news[j++][1] = y1 + m * (xmax - x1);
			news[j][0] = x2;
			news[j++][1] = y2;
		}
	}

	for (i = 0; i < j; i++) {
		points[i][0] = news[i][0];
		points[i][1] = news[i][1];
		news[i][0] = news[i][1] = 0;
	}

	if (j < limit)
		for (; i < limit; i++)
			points[i][0] = points[i][1] = 0;

	return j;
}

int bottomClip(int limit, int ymax) {
	int i, j = 0, x1, y1, x2, y2;
	float m;
	for (i = 0; i < limit; i++) {
		x1 = points[i][0];
		y1 = points[i][1];
		x2 = points[(i + 1) % limit][0];
		y2 = points[(i + 1) % limit][1];
		if (x2 - x1)
			m = (y2 - y1) * 1.0 / (x2 - x1);

		if (y1 > ymax && y2 > ymax)
			continue;
		if (y1 < ymax && y2 < ymax) {
			news[j][0] = x2;
			news[j++][1] = y2;
			continue;
		}
		if (y1 < ymax && y2 > ymax) {
			news[j][0] = x1 + (ymax - y1) / m;
			news[j++][1] = ymax;
			continue;
		}
		if (y1 > ymax && y2 < ymax) {
			news[j][0] = x1 + (ymax - y1) / m;
			news[j++][1] = ymax;
			news[j][0] = x2;
			news[j++][1] = y2;
		}
	}

	for (i = 0; i < j; i++) {
		points[i][0] = news[i][0];
		points[i][1] = news[i][1];
		news[i][0] = news[i][1] = 0;
	}

	if (j < limit)
		for (; i < limit; i++)
			points[i][0] = points[i][1] = 0;

	return j;
}