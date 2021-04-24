#include<bits/stdc++.h>
using namespace std;
vector <int> EulerTour,aa[100];
int vist[100];
void dfs(int node)
{
    vist[node] = 1;
//    cout <<" node:" <<node << endl;
    EulerTour.push_back(node);
    for(int i=0;i<aa[node].size();i++)
    {
        int temp = aa[node][i];
        if(!vist[temp])
        {
//            cout <<" temp:" << temp << endl;
            dfs(temp);
            EulerTour.push_back(node);
//            cout <<" temp:" << node << endl;
        }
    }
;}
/*
5
1 2
2 3
1 4
2 5
5 6

*/
int main()
{
    int n;
    cin >> n;
    for(int i=0;i<n;i++)
    {
        int node1,node2;
        cin >> node1 >> node2;
        aa[node1].push_back(node2);
        aa[node2].push_back(node1);
    }
    dfs(1);
    int num
}
