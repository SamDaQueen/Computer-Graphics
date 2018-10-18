#include<iostream>
#include<graphics.h>
#include<conio.h>
#include<math.h>
using namespace std;

int mat[50][50];
float result[3][3];
float FinalResult[3][1];

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

int multiplyFinalMatrix(float C[3][3], float D[3][1])
{
    for(int i=0; i<3; i++)
        for(int j=0; j<1; j++)
        {
            FinalResult[i][j] = 0;
            for(int k=0; k<3; k++)
                FinalResult[i][j] += C[i][k]*D[k][j];
        }
}

void translate()
{
    float tx, ty, x, y;
    float temp[3][3];
    cout<<"Enter translation vector(tx and ty): ";
    cin>>tx>>ty;
    cout<<"Choose point of translation: ";
    cin>>x>>y;
    float translateMatrix[3][3] = {1, 0, tx, 0, 1, ty, 0, 0, 1};
    float translatePoint[3][3] = {1, 0, -x, 0, 1, -y, 0, 0, 1};
    float translateInverse[3][3] = {1, 0, x, 0, 1, y, 0, 0, 1};
    multiply3x3matrix(translateInverse, translateMatrix);
    for(int i=0; i<3; i++)
        for(int j=0; j<3; j++)
        temp[i][j] = result[i][j];
    multiply3x3matrix(temp, translatePoint);
    cout<<endl;

    float A[3][1];
    for(int i=0; i<3; i++)
        A[i][0] = mat[i][0];
    float B[3][1];
    for(int i=0; i<3; i++)
        B[i][0] = mat[i][1];
    float C[3][1];
    for(int i=0; i<3; i++)
        C[i][0] = mat[i][2];

    multiplyFinalMatrix(result, A);
    for(int i=0; i<3; i++)
        for(int j=0; j<1; j++)
            A[i][j] = FinalResult[i][j];
    multiplyFinalMatrix(result, B);
    for(int i=0; i<3; i++)
        for(int j=0; j<1; j++)
            B[i][j] = FinalResult[i][j];
    multiplyFinalMatrix(result, C);
    for(int i=0; i<3; i++)
        for(int j=0; j<1; j++)
            C[i][j] = FinalResult[i][j];
    setcolor(11);
    line(A[0][0], A[1][0], B[0][0], B[1][0]);
    line(B[0][0], B[1][0], C[0][0], C[1][0]);
    line(C[0][0], C[1][0], A[0][0], A[1][0]);
}

void scaling()
{
    float Sx, Sy, x, y;
    float temp[3][3], theta;
    cout<<"Enter Scaling vector(Sx and Sy): ";
    cin>>Sx>>Sy;
    cout<<"Choose point of translation: ";
    cin>>x>>y;
    cout<<"Enter theta in degrees: ";
    cin>>theta;
    theta *= (3.14159265359/180);
    float RotateMatrixA[3][3] = {cos(theta), -sin(theta), 0, sin(theta), cos(theta), 0, 0, 0, 1};
    float RotateMatrixC[3][3] = {cos(theta), sin(theta), 0, -sin(theta), cos(theta), 0, 0, 0, 1};

    float ScalingMatrix[3][3] = {Sx, 0, 0, 0, Sy, 0, 0, 0, 1};
    float translatePoint[3][3] = {1, 0, -x, 0, 1, -y, 0, 0, 1};
    float translateInverse[3][3] = {1, 0, x, 0, 1, y, 0, 0, 1};

    multiply3x3matrix(translateInverse, RotateMatrixA);
    for(int i=0; i<3; i++)
        for(int j=0; j<3; j++)
        temp[i][j] = result[i][j];
    multiply3x3matrix(temp, ScalingMatrix);
    for(int i=0; i<3; i++)
        for(int j=0; j<3; j++)
        temp[i][j] = result[i][j];
    multiply3x3matrix(temp, RotateMatrixC);
    for(int i=0; i<3; i++)
        for(int j=0; j<3; j++)
        temp[i][j] = result[i][j];

    multiply3x3matrix(temp, translatePoint);
    cout<<endl;

    float A[3][1];
    for(int i=0; i<3; i++)
        A[i][0] = mat[i][0];
    float B[3][1];
    for(int i=0; i<3; i++)
        B[i][0] = mat[i][1];
    float C[3][1];
    for(int i=0; i<3; i++)
        C[i][0] = mat[i][2];

    multiplyFinalMatrix(result, A);
    for(int i=0; i<3; i++)
        for(int j=0; j<1; j++)
            A[i][j] = FinalResult[i][j];
    multiplyFinalMatrix(result, B);
    for(int i=0; i<3; i++)
        for(int j=0; j<1; j++)
            B[i][j] = FinalResult[i][j];
    multiplyFinalMatrix(result, C);
    for(int i=0; i<3; i++)
        for(int j=0; j<1; j++)
            C[i][j] = FinalResult[i][j];

    setcolor(14);
    line(A[0][0], A[1][0], B[0][0], B[1][0]);
    line(B[0][0], B[1][0], C[0][0], C[1][0]);
    line(C[0][0], C[1][0], A[0][0], A[1][0]);
}

void rotation()
{
    int x, y;
    float temp[3][3];
    double theta;
    cout<<"Enter theta in degrees: ";
    cin>>theta;
    theta *= (3.14159265359/180);
    int choice;
    cout<<"\nChoose 1.Clockwise or 2.Anticlockwise: ";
    cin>>choice;
    cout<<"Choose point of translation: ";
    cin>>x>>y;
    float RotateMatrix[3][3];
    float RotateMatrixA[3][3] = {cos(theta), -sin(theta), 0, sin(theta), cos(theta), 0, 0, 0, 1};
    float RotateMatrixC[3][3] = {cos(theta), sin(theta), 0, -sin(theta), cos(theta), 0, 0, 0, 1};
    if(choice == 1)
        for(int i=0; i<3; i++)
            for(int j=0; j<3; j++)
                RotateMatrix[i][j] = RotateMatrixA[i][j];
    else
        for(int i=0; i<3; i++)
            for(int j=0; j<3; j++)
                RotateMatrix[i][j] = RotateMatrixC[i][j];

    float translatePoint[3][3] = {1, 0, -x, 0, 1, -y, 0, 0, 1};
    float translateInverse[3][3] = {1, 0, x, 0, 1, y, 0, 0, 1};
    multiply3x3matrix(translateInverse, RotateMatrix);
    for(int i=0; i<3; i++)
        for(int j=0; j<3; j++)
        temp[i][j] = result[i][j];
    multiply3x3matrix(temp, translatePoint);
    cout<<endl;

    float A[3][1];
    for(int i=0; i<3; i++)
        A[i][0] = mat[i][0];
    float B[3][1];
    for(int i=0; i<3; i++)
        B[i][0] = mat[i][1];
    float C[3][1];
    for(int i=0; i<3; i++)
        C[i][0] = mat[i][2];

    multiplyFinalMatrix(result, A);
    for(int i=0; i<3; i++)
        for(int j=0; j<1; j++)
            A[i][j] = FinalResult[i][j];
    multiplyFinalMatrix(result, B);
    for(int i=0; i<3; i++)
        for(int j=0; j<1; j++)
            B[i][j] = FinalResult[i][j];
    multiplyFinalMatrix(result, C);
    for(int i=0; i<3; i++)
        for(int j=0; j<1; j++)
            C[i][j] = FinalResult[i][j];

    setcolor(4);
    line(A[0][0], A[1][0], B[0][0], B[1][0]);
    line(B[0][0], B[1][0], C[0][0], C[1][0]);
    line(C[0][0], C[1][0], A[0][0], A[1][0]);
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

    line(mat[0][0], mat[1][0], mat[0][1], mat[1][1]);
    line(mat[0][1], mat[1][1], mat[0][2], mat[1][2]);
    line(mat[0][2], mat[1][2], mat[0][0], mat[1][0]);

    int choice=1;
    do{
    cout<<"\nEnter your choice:\t1.Translation\t2.Scaling\t3.Rotation\t";
    cin>>choice;
    switch(choice)
    {
    case 1:
        translate();    break;
    case 2:
        scaling();      break;
    case 3:
        rotation();     break;
    }
    }while(choice!=0);
    getch();
    closegraph();
    return 0;
}
