#include<bits/stdc++.h>
using namespace std;


int main()
{
    int r = 3;
    int cx = 1;
    int cy = 2;
    float x = 0,y = 0;
    vector <int> v;
    cout << " Second Order Polunomiual Circle" << endl;
    printf("x || y=root(r*r - x*x) || round(y) \n");
    while(x<=y)
    {
        y = sqrt(r*r - x*x);
        cout << x << " || " << y << " || " << round(y) << endl;
        v.push_back(x);
        v.push_back(round(y));
        x++;
    }
    vector <int > eightX,eightY,answer0,answer1;
    eightX.push_back(1);
    eightY.push_back(1);

    eightX.push_back(-1);
    eightY.push_back(1);

    eightX.push_back(1);
    eightY.push_back(-1);

    eightX.push_back(-1);
    eightY.push_back(-1);

    eightX.push_back(1);
    eightY.push_back(1);

    eightX.push_back(1);
    eightY.push_back(-1);

    eightX.push_back(-1);
    eightY.push_back(1);

    eightX.push_back(-1);
    eightY.push_back(-1);


    int iteration = (v.size());
    for(int i=0; i<v.size(); i+=2)
    {
        for(int j=0; j<8; j++)
        {
            if(j<4){
                answer0.push_back(v[i]*eightX[j] + cx);
                answer1.push_back(v[i+1]*eightY[j] + cy);
            }else{
                answer0.push_back(v[i+1]*eightX[j] + cx);
                answer1.push_back(v[i]*eightY[j] + cy);

            }
        }
    }

    int temp1 = 0,temp2 = 8;
    for(int j=0; j<iteration;j+=2)
    {
        cout << "Column : " << j/2 << endl;
        cout << "(x,y) :" << v[j] << " " << v[j+1] << endl;
        for(int i=temp1; i<temp2; i++)
        {
            char x = eightX[i]>0?'+':'-';
            char y = eightY[i]>0?'+':'-';
            printf(" (%cx + %d , %cy + %d) : ",x,cx,y,cy);
            cout << answer0[ i] << "," << answer1[i] << endl;
        }
        temp1=temp2;
        temp2+=8;
    }
}
