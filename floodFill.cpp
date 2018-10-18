#include<iostream>
#include<graphics.h>
using namespace std;

void floodfill(int x, int y, int bgColor, int fillColor)
{
    int current = getpixel(x, y);
    if(current==bgColor)
    {
        putpixel(x, y, fillColor);
        floodfill(x+1, y, 0, fillColor);
        floodfill(x, y+1, 0, fillColor);
        floodfill(x-1, y, 0, fillColor);
        floodfill(x, y-1, 0, fillColor);
    }
}

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\TC\\BGI");

    int fillColor, x[10], y[10], i, a, b, n;
    cout<<"Enter n: ";
    cin>>n;
    cout<<"Enter co-ordinates of "<<n<<"-sided polygon: ";
    cout<<"\nEnter x: ";
    for(i=0; i<n; i++)
        cin>>x[i];
    cout<<"Enter y: ";
    for(i=0; i<n; i++)
        cin>>y[i];

    line(x[n-1], y[n-1], x[0], y[0]);
    for(i=0; i<n-1; i++)
        line(x[i], y[i], x[i+1], y[i+1]);


    cout<<"Enter fill color(0-15): ";
    cin>>fillColor;
    cout<<"Enter starting point(x, y): ";
    cin>>a>>b;
    floodfill(a, b, 0, fillColor);

    getch();
    closegraph();
}
