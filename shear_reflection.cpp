#include<iostream>
#include<graphics.h>
#include<conio.h>
#include<math.h>
using namespace std;

float mat[3][3];
float result[3][3];

int multiply3x3matrix(float A[3][3], float B[3][3])
{
    for(int i=0; i<3; i++)
        for(int j=0; j<3; j++)
            result[i][j] = 0;
    for(int i=0; i<3; i++)
        for(int j=0; j<3; j++)
            for(int k=0; k<3; k++)
                result[i][j] += A[i][k]*B[k][j];
}

void shear()
{
    setcolor(WHITE);
    line(mat[0][0], mat[1][0], mat[0][1], mat[1][1]);
    line(mat[0][1], mat[1][1], mat[0][2], mat[1][2]);
    line(mat[0][2], mat[1][2], mat[0][0], mat[1][0]);

    int sx, sy;
    cout<<"Enter shear vector(Sx and Sy): ";
    cin>>sx>>sy;

    float Shx[3][3] = {1, 0, 0, sy, 1, 0, 0, 0, 1};
    float Shy[3][3] = {1, sx, 0, 0, 1, 0, 0, 0, 1};
    multiply3x3matrix(Shy, mat);
    setcolor(YELLOW);
    line(result[0][0], result[1][0], result[0][1], result[1][1]);
    line(result[0][1], result[1][1], result[0][2], result[1][2]);
    line(result[0][2], result[1][2], result[0][0], result[1][0]);

    multiply3x3matrix(Shx, mat);
    setcolor(GREEN);
    line(result[0][0], result[1][0], result[0][1], result[1][1]);
    line(result[0][1], result[1][1], result[0][2], result[1][2]);
    line(result[0][2], result[1][2], result[0][0], result[1][0]);
}

void reflection()
{
    cleardevice();
    setcolor(WHITE);
    line(mat[0][0] + getmaxx()/2, mat[1][0] + getmaxy()/2, mat[0][1] + getmaxx()/2, mat[1][1] + getmaxy()/2);
    line(mat[0][1] + getmaxx()/2, mat[1][1] + getmaxy()/2, mat[0][2] + getmaxx()/2, mat[1][2] + getmaxy()/2);
    line(mat[0][2] + getmaxx()/2, mat[1][2] + getmaxy()/2, mat[0][0] + getmaxx()/2, mat[1][0] + getmaxy()/2);
    int choice;
    line(0, getmaxy()/2, getmaxx(), getmaxy()/2);
    line(getmaxx()/2, 0, getmaxx()/2, getmaxy());
    float reflectX[3][3] = {1, 0, 0, 0, -1, 0, 0, 0, 1};
    float reflectY[3][3] = {-1, 0, 0, 0, 1, 0, 0, 0, 1};
    float reflectXY[3][3] = {-1, 0, 0, 0, -1, 0, 0, 0, 1};
    cout<<"\nChoose 1.X 2.Y 3.XY :\t ";
    cin>>choice;
    float reflect[3][3];
    if(choice == 1)
        for(int i=0; i<3; i++)
            for(int j=0; j<3; j++)
                reflect[i][j] = reflectX[i][j];
    else if(choice == 2)
        for(int i=0; i<3; i++)
            for(int j=0; j<3; j++)
                reflect[i][j] = reflectY[i][j];
    else
        for(int i=0; i<3; i++)
            for(int j=0; j<3; j++)
                reflect[i][j] = reflectXY[i][j];

    multiply3x3matrix(reflect, mat);

    setcolor(CYAN);
    line(result[0][0] + getmaxx()/2, result[1][0] + getmaxy()/2, result[0][1] + getmaxx()/2, result[1][1] + getmaxy()/2);
    line(result[0][1] + getmaxx()/2, result[1][1] + getmaxy()/2, result[0][2] + getmaxx()/2, result[1][2] + getmaxy()/2);
    line(result[0][2] + getmaxx()/2, result[1][2] + getmaxy()/2, result[0][0] + getmaxx()/2, result[1][0] + getmaxy()/2);
}

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\TC\\BGI");

    int i, j;
    cout<<"Enter the co-ordinates of triangle ABC:\n";
    cout<<"Enter ax, bx, cx: ";
    for(i=0; i<3; i++)
        cin>>mat[0][i];
    cout<<"Enter ay, by, cy: ";
    for(i=0; i<3; i++)
        cin>>mat[1][i];
    for(i=0; i<3; i++)
        mat[2][i] = 1;

    int choice=1;
    do{
    cout<<"\nEnter your choice:\t1.Shear\t2.Reflection\t";
    cin>>choice;
    switch(choice)
    {
    case 1:
        shear();    break;
    case 2:
        reflection();      break;
    }
    }while(choice!=0);
    getch();
    closegraph();
    return 0;
}
