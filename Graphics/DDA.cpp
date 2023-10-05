#include <stdio.h>
#include <conio.h>  
#include <graphics.h>  

int main()  
{  
    int gd = DETECT ,gm, i = 1;  
    float x, y,dx,dy,steps;  
    int x0, x1, y0, y1; 
    initwindow(700, 700, "DDA Line Drawing Algorithm");
    printf("Enter the starting coordinates : ");
    scanf("%d %d", &x0, &y0);
    printf("Enter the ending coordinates : ");
    scanf("%d %d", &x1, &y1);

    dx = (float)(x1 - x0);  
    dy = (float)(y1 - y0);  
    if(dx>=dy)  
           {  
        steps = dx;  
    }  
    else  
           {  
        steps = dy;  
    }  

    dx = dx/steps;  
    dy = dy/steps;  
    x = x0;  
    y = y0;  

    while(i<= steps)  
    {  
        putpixel(x, y, 9);  
        x += dx;  
        y += dy;  
        i=i+1; 
        delay(10);
    }  
    getch();  
    closegraph(); 
    return 0;
}  