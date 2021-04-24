#include<bits/stdc++.h>
using namespace std;
int node,edge;
vector <int> v[1000];
int vist[1000];
int dist[1000];
void dfs(int node)
{
    vist[node] = 1;
    for(int i=0;i<v[node].size();i++)
    {
        int temp = v[node][i];
        if(vist[temp]==0)
        {
            dist[temp]=dist[node] + 1;
            dfs(temp);
        }
    }
}
int main()
{
	cin >> node>> edge;
	for(int i=0;i<edge;i++)
    {
        int x,y;
        cin >>x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    int city,destination;
    cin >> city >> destination;
    dfs(city);
    cout << "Destination  : " << dist[destination] << endl;

}
