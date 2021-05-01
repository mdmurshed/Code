#include<bits/stdc++.h>
using namespace std;


int main()
{
    int r = 4;
    int cx = 0;
    int cy = 1;
    vector <int> v;
    int d = 3 - 2*r;
    int x = 0;
    int y = r;
    cout << " BresenhamCircle " << endl;
    cout << "d : " << r << " " << endl;
    v.push_back(x);
    v.push_back(y);
    v.push_back(d);
    while(x<=y)
    {
        if(d<0)
        {
            d = d+4*x+6;
        }
        else
        {
            d = d + 4*(x-y) + 10;
            y--;
        }
        x++;
        if(x>y) break;
        v.push_back(x);
        v.push_back(y);
        v.push_back(d);

    }
    printf(" (x,y)    ||        d         || (x+1,y+1)\n");
    for(int i=0; i<v.size()-3; i+=3)
    {
        printf("(%d,%d)    ||    %d     || (%d,%d) \n",v[i],v[i+1],v[i+2],v[i+3],v[i+4]);
        //cout <<v[i] << "," <<v[i+1] << " " << v[i+2] << " "<< v[i+3]<< ","<<v[i+4]<< endl;
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
    for(int i=0; i<v.size(); i+=3)
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
    /*
    for(int i=0;i<answer0.size();i++){
        cout << answer0[i] << " " << answer1[i] << endl;
    }
    */
    int temp1 = 0,temp2 = 8;
    for(int j=0; j<iteration;j+=3)
    {
        cout << "Column : " << j/3 << endl;
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
