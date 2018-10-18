
#include<iostream>
#include<graphics.h>
#include<conio.h>
using namespace std;

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\TC\\BGI");

    int rx, ry, xc, yc;
    float x, y, P1, P2;
    cout<<"Enter rx, ry and center(x,y): ";
    cin>>rx>>ry>>xc>>yc;

    for(int i=5; i>0; i--, rx--, ry--)  {
    x = 0;
    y = ry;
    P1 = ry*ry - rx*rx*ry + (1/4)*rx*rx;
    while(ry*ry*x<rx*rx*y){
        if(P1<0)
        {
            P1 += 2*ry*ry*(x+1) + ry*ry;
            x++;
        }
        else
        {
            P1 += ry*ry*(3 + 2*x) + 2*rx*rx*(2-y);
            x++;
            y--;
        }
    putpixel(x + xc, y + yc, rand()%14);
    putpixel(-x + xc, y + yc, rand()%14);
    putpixel(x + xc, -y + yc, rand()%14);
    putpixel(-x + xc, -y + yc, rand()%14);
    delay(5);
    };

    P2 = ry*ry*(x + 1/2)*(x + 1/2) - rx*rx*ry*ry + rx*rx*(y-1)*(y-1);
    while(y>0){
        if(P2>0)
        {
            y--;
            P2 += -2*rx*rx*y + rx*rx;
        }
        else
        {
            x++;
            y--;
            P2 += 2*ry*ry*(x+1) - 2*rx*rx*(y-1) + rx*rx;
        }
    putpixel(x + xc, y + yc, rand()%14);
    putpixel(-x + xc, y + yc, rand()%14);
    putpixel(x + xc, -y + yc, rand()%14);
    putpixel(-x + xc, -y + yc, rand()%14);
    delay(5);
    };
    }

    getch();
    closegraph();
    return 0;
}
