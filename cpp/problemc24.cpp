#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    while(n--)
    {
        int x;
        cin >> x;
        map <int,int>index,mp;
        int pre=-1,first,last;
        for(int i=1;i<=x;i++)
        {
            int num;
            cin >> num;
            if(i == 1) first = num;
            if(i == x) last = num;
            index[num]++;
            if(pre!=num){
                mp[num]++;
                pre=num;
            }
        }
        int mi = 9999999;
        map<int,int> :: iterator it;
        for(it = mp.begin();it!=mp.end();it++)
        {
            cout << it->first << " " << it->second  << endl << " test:";
            if(index[it->first] == x) cout << 0 << endl;
            else if(it->second == 1 &&(it->first==first || it->first == last) ) cout << 1 << endl;
            else if(it->second == 1 &&!(it->first==first && it->first == last) ) cout << 2 << endl;
            else if(it->first==first && it->first == last && it->second == 2) cout << 1<< endl;
            else if(it->first==first && it->first == last) cout << (it->second-1)<< endl;
            else if(it->first==first || it->first == last) cout << (it->second) << endl;
            else cout << it->second + 1 << endl;
        }
    }
}
