#include<iostream>
#include<graphics.h>
using namespace std;

int xmin, xmax, ymin, ymax;
int x1, y1, x2, y2;
bool wasChanged = false;

bool TBRL(int tbrl[], int x, int y)
{
    bool hasOne = false;
    for(int i=0; i<4; i++)
        tbrl[i] = 0;
    if(x<xmin)  {
        tbrl[3] = 1;
        hasOne = true;
    }
    else if(x>xmax)  {
        tbrl[2] = 1;
        hasOne = true;
    }
    if(y<ymin)  {
        tbrl[1] = 1;
        hasOne = true;
    }
    else if(y>ymax)  {
        tbrl[0] = 1;
        hasOne = true;
    }
    return hasOne;
}

bool intersectingPoints(int tbrl[], int xy[], int x, int y)
{
    bool hasOne = false;
    if(tbrl[0]) {
        wasChanged = true;
        xy[1] = ymax;
        xy[0] = x1 + ((x2-x1)/(y2-y1))*(xy[1] - y1);
        hasOne = TBRL(tbrl, xy[0], xy[1]);
    }
    else if(tbrl[1]) {
        wasChanged = true;
        xy[1] = ymin;
        xy[0] = x1 + ((x2-x1)/(y2-y1))*(xy[1] - y1);
        hasOne = TBRL(tbrl, xy[0], xy[1]);
    }
    else if(tbrl[2]) {
        wasChanged = true;
        xy[0] = xmax;
        xy[1] = y1 + ((y2-y1)/(x2-x1))*(xy[0] - x1);
        hasOne = TBRL(tbrl, xy[0], xy[1]);
    }
    else if(tbrl[3]) {
        wasChanged = true;
        xy[0] = xmin;
        xy[1] = y1 + ((y2-y1)/(x2-x1))*(xy[0] - x1);
        hasOne = TBRL(tbrl, xy[0], xy[1]);
    }
    return hasOne;
}

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    int i, choice=1;
    cout<<"Enter co-ordinates for window ABCD:\n\n";
    cout<<"xmin, xmax, ymin, ymax: ";
    cin>>xmin>>xmax>>ymin>>ymax;
    rectangle(xmin, ymin, xmax, ymax);

    int P_TBRL[4] = {0,0,0,0};
    int Q_TBRL[4] = {0,0,0,0};

    do{
    bool One, Two = false;
    cout<<"\n\nEnter co-ordinates for lines\nP(x1, y1) and Q(x2, y2): ";
    cin>>x1>>y1>>x2>>y2;

    cout<<"\nP_TBRL = ";
    One = TBRL(P_TBRL, x1, y1);
    for(int i=0; i<4; i++)
        cout<<P_TBRL[i];
    cout<<endl;
    cout<<"Q_TBRL = ";
    Two = TBRL(Q_TBRL, x2, y2);
    for(int i=0; i<4; i++)
        cout<<Q_TBRL[i];
    cout<<endl;

    setcolor(YELLOW);
    line(x1, y1, x2, y2);

    while(One || Two){
        cout<<"\nDoes not fit entirely in window!\n";
        int xy[2];
        One = intersectingPoints(P_TBRL, xy, x1, y1);
        if(wasChanged)  {
            x1 = xy[0]; y1 = xy[1];
            wasChanged = false;
        }
        else {
            Two = intersectingPoints(Q_TBRL, xy, x2, y2);
            if(wasChanged)  {
                x2 = xy[0]; y2 = xy[1];
                wasChanged = false;
            }
        }
        cout<<"\nP_TBRL = ";
        for(int i=0; i<4; i++)
            cout<<P_TBRL[i];
        cout<<endl;
        cout<<"Q_TBRL = ";
        for(int i=0; i<4; i++)
            cout<<Q_TBRL[i];
        cout<<endl;
        setcolor(GREEN);
        line(x1, y1, x2, y2);
    }
    cout<<"\n(x1, y1) = "<<x1<<", "<<y1;
    cout<<"\n(x2, y2) = "<<x2<<", "<<y2<<endl;
    setcolor(WHITE);
    line(x1, y1, x2, y2);

    cout<<"\nContinue?\t1.Yes\t0.No:\t";
    cin>>choice;
    }while(choice!=0);
    getch();
    closegraph();
}
