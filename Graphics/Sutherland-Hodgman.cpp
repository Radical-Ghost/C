#include<stdio.h>
#include<graphics.h>
#include<conio.h>
#include<stdlib.h>

int main() {
    int n, *x, i, k=0, w[] = {100,100,500,100,500,500,100,500,100,100};

    int width = GetSystemMetrics(SM_CXSCREEN), height = GetSystemMetrics(SM_CYSCREEN);
    initwindow(width, height, (char*)"Polygon Clipping", -3, -5);

    setcolor(GREEN);
    drawpoly(5,w); //window drawn

    printf("Enter the no. of vertices of polygon: ");
    scanf("%d",&n);

    x = (int *)malloc(n * 2 * sizeof(int));
    printf("Enter the coordinates of points:\n");
    for(i=0; i<n*2; i+=2) {  //reading vertices of polygon
        printf("(x%d,y%d): ", k, k);
        scanf("%d %d", &x[i], &x[i+1]);
        k++;
    }

    x[n*2]=x[0]; //assigning the coordinates of first vertex to last additional vertex for drawpoly method.
    x[n*2+1]=x[1];
    setcolor(WHITE);
    drawpoly(n+1, x);
    getch();

    setcolor(GREEN);
    drawpoly(5, w);
    setfillstyle(SOLID_FILL, BLACK);
    floodfill(2, 2, GREEN);
    getch();

    cleardevice();
    closegraph();
    return 0;
}