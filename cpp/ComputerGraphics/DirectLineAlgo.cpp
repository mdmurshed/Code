#include<bits/stdc++.h>

using namespace std;


int main()
{
    float x1 = 2;
    float y1 = 0;
    float x2 = 7;
    float y2 = 4;
    float m = (y2-y1)/(x2-x1);
    cout <<"Slope m = " <<m << endl;
    float b = y1 - m*x1;
    printf("b = y1 - m*x1 = %.2f - %.2f*%.2f = %.2f\n",y1,m,x1,b);
    float x,y;
    if(abs(m)<=1)
    {
        if(x1>x2){
            float temp;
            temp = x1;
            x1 = x2;
            x2 = temp;
            temp = y1;
            y1 = y2;
            y2 = temp;

        }
        cout << "m <= 1" << endl;
        x = x1;
        y = y1;
        cout << "x" << " || y = mx+b  ||   round(y)" << endl;
        cout << x << " || "<<y << " || " << y<< endl;
        while(x<x2)
        {
            x++;
            y = m*x + b;
            printf("%.2f || %.2f*%.2f + %.2f  = %.2f || %.f\n",x,m,x,b,y,floor(y+.5));
        }
    }
    else{
        if(y1>y2){
            float temp;
            temp = x1;
            x1 = x2;
            x2 = temp;
            temp = y1;
            y1 = y2;
            y2 = temp;

        }
        cout << "m > 1" << endl;
        x = x1;
        y = y1;
        cout << "y" << " || x = (y-b)/m || round(x)" << endl;
        cout << y << " || "<<x  << " || " << x<< endl;
        while(y<=y2)
        {
            y++;
            x = (y-b)/m;
            printf("%.2f || (%.2f-%.2f)/%.2f = %.2f || %.f\n",y,y,b,m,x,floor(x+.5));
        }
    }
}
