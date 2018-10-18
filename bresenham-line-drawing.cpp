
#include<iostream>
#include<graphics.h>
using namespace std;

int main()
{
    int gd = DETECT, gm, x1, y1, x2, y2;
    float x, y, xi, yi, dx, dy, P;

    initgraph(&gd, &gm, "");

    cout<<"Enter x1 y1: ";
    cin>>x1>>y1;
    //Samreen Reyaz B005
    cout<<"Enter x2 y2: ";
    cin>>x2>>y2;

    dx = x2 - x1;
    dy = y2 - y1;
    putpixel(x, y, rand()%14);

    x = x1;
    y = y1;

    if(abs(dx) >= abs(dy))    {
        P = 2*abs(dy) - abs(dx);
        while(x<=x2 || y<=y2)   {
            if(P<0) {
                xi = dx/abs(dx);
                yi = 0;
                P += 2*abs(dy);
            }
            else    {
                xi = dx/abs(dx);
                yi = dy/abs(dy);
                P += 2*abs(dy) - 2*abs(dx);
            }
            x += xi;
            y += yi;
            putpixel(x, y, rand()%14);
            delay(50);
        }
    }
    else    {
        P = 2*abs(dx) - abs(dy);
        while(x<=x2 || y<=y2)   {
            if(P<0) {
                xi = 0;
                yi = dy/abs(dy);
                P += 2*abs(dx);
            }
            else{
                xi = dx/abs(dx);
                yi = dy/abs(dy);
                P += 2*abs(dx) - 2*abs(dy);
            }
            x += xi;
            y += yi;
            putpixel(x, y, rand()%14);
            delay(50);
        }
    }
    getch();
    closegraph();
}
