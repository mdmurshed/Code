#include<bits/stdc++.h>
using namespace std;


int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        string str;
        cin >> str;
        int count = 0;
        int fs = 0,fe = 0,ts = 0,te = 0;
        bool third = true,first = true;
        for(int i=0;i<str.length();i++){
            if(str[i]=='('){
                fs++;
            }
            else if(str[i]==')'){
                fe++;
            }
            else if(str[i]=='['){
                ts++;
            }
            else if(str[i]==']'){
                te++;
            }
            if(fs>=fe && fe==1){
                count++;
                fs--;
                fe--;
            }
            else {
                fe = 0;
            }
            if(ts>=te&& te == 1){
                count++;
                ts--;
                te--;
            }else te=0;
        }
        cout << count << endl;
    }
}
