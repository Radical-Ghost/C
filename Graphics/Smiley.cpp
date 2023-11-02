#include<stdio.h>
#include<graphics.h>

int main() {
    int width = GetSystemMetrics(SM_CXSCREEN), height = GetSystemMetrics(SM_CYSCREEN);
    initwindow(width, height, (char*)"Smiley", -3, -5);

    setcolor(YELLOW);
    circle(300, 300, 100);
    setfillstyle(SOLID_FILL, YELLOW);
    floodfill(300, 300, YELLOW);

    setcolor(BLACK);
    setfillstyle(SOLID_FILL, BLACK);

    fillellipse(340, 285, 10, 20);
    fillellipse(260, 285, 10, 20);

    for(int i = 10; i  <= 25; i++) {
        ellipse(300, 335, 205, 335, 50, i); 
    }     

    getch();
    closegraph();
    return 0;
}