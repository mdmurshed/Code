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
    float x,y;
    float temp;
    if(abs(m)<=1)
    {
        if(x1>x2){

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
        cout << "x" << " || y = y+m  ||  round(y)" << endl;
        cout << x << "     ||     "<< y <<"    ||    " << y<< endl;
        while(x<x2)
        {
            x++;
            temp = y;
            y = y+m;
            printf("%.2f || %.2f + %.2f = %.2f || %.f\n",x,temp,m,y,floor(y+.5));
        }
    }
    else{
        cout << "m > 1" << endl;
        x = x1;
        y = y1;
        cout << "y" << " || x = x + 1/m     || round(x)" << endl;
        cout << y << " ||   "<< x << "    ||   " << x<< endl;
        while(y<y2)
        {
            y++;
            temp = x;
            x = x+(1/m);
            printf("%.2f || %.2f + %.2f  = %.2f || %.f\n",y,temp,(1/m),x,floor(x+.5));
        }
    }
}

