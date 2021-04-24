#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;


int main()
{
    int t;
    ll a,b,x,y,z;
    cin >> t;
    while(t--)
    {
        cin >> a >> b >> x >> y >> z;
        if(y<x)
        {
            ll temp = y;
            y = x;
            x = temp;
            temp = a;
            a = b;
            b = temp;
        }
        if(a<=b)
            {
                int temp= a-z;
                if(temp>=x)
                    cout << temp*b << endl;
                else
                {
                    z = x - temp;
                    cout << temp*(b-z) << endl;
                }
            }
            else if(a>b)
            {
                int temp= b-z;
                if(temp>=y)
                    cout << temp*a << endl;
                else
                {
                    z = y - temp;
                    cout << temp*(a-z) << endl;
                }
            }
    }


}
