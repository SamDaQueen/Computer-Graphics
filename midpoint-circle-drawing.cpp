#include<iostream>
#include<graphics.h>
#include<conio.h>
using namespace std;

int main()
{
    int gd = DETECT, gm = CGAC0;
    initgraph(&gd, &gm, "C:\\TC\\BGI");

    int r, xc, yc;
    float x, y, P;
    cout<<"Enter radius and center(x,y): ";
    cin>>r>>xc>>yc;

    for(int i=5; i>0; i--, r--)  {
    x = 0;
    y = r;
    P = (5/4) - r;
    while(x<y){
        if(P<0)
        {
            P += 2*x + 3;
            x += 1;
            y = y;
        }
        else
        {
            P += 2*x - 2*y +  5;
            x += 1;
            y -= 1;
        }
    putpixel(x + xc, y + yc, rand()%14);
    putpixel(y + xc, x + yc, rand()%14);
    putpixel(x + xc, -y + yc, rand()%14);
    putpixel(-y + xc, x + yc, rand()%14);
    putpixel(-x + xc, -y + yc, rand()%14);
    putpixel(-y + xc, -x + yc, rand()%14);
    putpixel(-x + xc, y + yc, rand()%14);
    putpixel(y + xc, -x + yc, rand()%14);
    //delay(5);
    };
    }

    getch();
    closegraph();
    return 0;
}
