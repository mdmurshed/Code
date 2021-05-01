#include<bits/stdc++.h>
#include<sstream>
using namespace std;

/*
int x1 = 2;
    int y1 = 0;
    int x2 = 10;
    int y2 = 17;
    string str = "";
    string temp;
    stringstream ss;
    ss << x2;
    ss >> temp;
    str+=temp;
    cout << str<<endl;
*/
int main()
{
    int x1 = 2;
    int y1 = 0;
    int x2 = 7;
    int y2 = 4;
    float m = (y2-y1)/(x2-x1);
    printf("slope m = %.2f \n",m);
    int x,y;
    int temp;
    if(abs(m)<1)
    {
        if(x1>x2){

            temp = x1;
            x1 = x2;
            x2 = temp;
            temp = y1;
            y1 = y2;
            y2 = temp;

        }
        cout << "m < 1" << endl;
        int dx = x2 - x1;
        int dy = y2 - y1;
        x = x1;
        y = y1;
        int p = 2*dy -dx;
        cout << " dx = " << dx << " , dy = " << dy << " ,p = " << p << endl;
        printf("k   ||   p    ||   (x,y) \n");
        int k = -1;
        printf("%d  ||                 || (%d,%d)  \n",k++,x,y);

        while(x<x2)
        {
            x++;
            string str,st;
            if(p<0){
                temp = p;
                p = p+2*dy;
                //printf("p=p+2*dy = %d + 2*%d  =  %d   \n",temp,dy,p);
                str = "p=p+2*dy = ";
                stringstream ss,ss1,ss2;
                ss << temp;
                ss >> st;
                str+=st;

                ss1 << dy;
                ss1 >> st;
                str+=" + 2*";
                str+=st;

                ss2 << p;
                ss2 >> st;
                str+=" = ";
                str+=st;
                //cout << str << endl;

            }
            else{
                temp = p;
                p=p+2*dy-2*dx;
                y++;
                //printf("p=p+2*dy - 2*dx = %d + 2*%d - 2*%d = %d   \n",temp,dy,dx,p);
                str = "p=p+2*dy - 2*dx = ";
                stringstream ss,ss1,ss2,ss3;
                ss << temp;
                ss >> st;
                str+=st;

                ss1 << dy;
                ss1 >> st;
                str+=" + 2*";
                str+=st;

                ss2 << dx;
                ss2 >> st;
                str+=" - 2*";
                str+=st;

                ss3 << p;
                ss3 >> st;
                str+=" = ";
                str+=st;
                //cout << str << endl;
            }
            printf("%d  ||  %d  || (%d,%d)  \n",k++,temp,x,y);
            cout <<str << endl;
        }
    }
    else{
        cout << "m > 1" << endl;
        if(y1>y2){

            temp = x1;
            x1 = x2;
            x2 = temp;
            temp = y1;
            y1 = y2;
            y2 = temp;

        }
        int dx = x2 - x1;
        int dy = y2 - y1;
        x = x1;
        y = y1;
        int p = ((2*dx) - dy);
        cout << " dx = " << dx << " , dy = " << dy << " ,p = " << p << endl;
        printf("k   ||   p    ||   (x,y) \n");
        int k = -1;
        printf("%d  ||                 || (%d,%d)  \n",k++,x,y);
        while(y<y2)
        {
            string str,st;
            temp = p;
            y++;
            if(p<0){
                p = p+2*dx;
                str = "p=p+2*dx = ";
                stringstream ss,ss1,ss2;
                ss << temp;
                ss >> st;
                str+=st;

                ss1 << dx;
                ss1 >> st;
                str+=" + 2*";
                str+=st;

                ss2 << p;
                ss2 >> st;
                str+=" = ";
                str+=st;
                //cout << str << endl;
            }
            else{
                p=p+2*dx-2*dy;
                x++;
                str = "p=p+2*dx - 2*dy = ";
                stringstream ss,ss1,ss2,ss3;
                ss << temp;
                ss >> st;
                str+=st;

                ss1 << dx;
                ss1 >> st;
                str+=" + 2*";
                str+=st;

                ss2 << dy;
                ss2 >> st;
                str+=" - 2*";
                str+=st;

                ss3 << p;
                ss3 >> st;
                str+=" = ";
                str+=st;
            }
            printf("%d  ||  %d  || (%d,%d)  \n",k++,temp,x,y);
            cout << str << endl;
        }
    }
}
