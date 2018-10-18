
#include<iostream>
#include<graphics.h>
#include<conio.h>
using namespace std;

int main()
{
    int gd = DETECT, gm, x1, y1, x2, y2, k, j;
    float x, y, xi, yi, s, dx, dy;

    initgraph(&gd, &gm, "C:\\TC\\BGI");

    //cout<<"Enter x1 y1: ";
    //cin>>x1>>y1;
    //cout<<"Enter x2 y2: ";
    //cin>>x2>>y2;
    x1 = y1 = 100;
    x2 = y2 = 200;

    for(int i=0, j=1; i<4; i++, j++)  {
    dx = x2 - x1;
    dy = y2 - y1;

    putpixel(x, y, 8);
    s = abs(dx) > abs(dy) ? abs(dx) : abs(dy);
    xi = dx/ s;
    yi = dy/ s;

    x = x1;
    y = y1;
    for(k=0; k<s; k++)
    {
        x += xi;
        y += yi;
        putpixel(int(x + 0.5), int(y + 0.5), 14);
        //delay(20);
    }
    x1 = x2;
    y1 = y2;
    if(j%2==0)  {
        x2 += 100;
        y2 += 100;
    }
    else    {
        x2 -= 100;
        y2 += 100;
    }
    }
    getch();
    closegraph();
}
