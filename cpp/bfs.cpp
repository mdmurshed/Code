#include<bits/stdc++.h>
using namespace std;
vector <int> v[1000];
int vist[1000];
int dist[1000];
bool ok = false;

void bfs(int node)
{
    queue <int> q;
    q.push(node);
    vist[node] = 1;
    while(!q.empty())
    {
        int temp = q.front();
        q.pop();
        for(int i=0;i<v[temp].size();i++)
        {
            int t= v[temp][i];
            if(!vist[t])
            {
                dist[t] = dist[temp]+1;
                q.push(t);
            }
        }
    }
}
void dfs(int node)
{
    vist[node]=1;
//    cout << "node : " << node << endl;
    int temp;
    for(int i =0;i<v[node].size();i++)
    {
        parent[node] = 1;
        temp = v[node][i];
//        cout << "tempNode :" << temp << endl;
        if(vist[temp]==0)
        {
//            dist[temp] = dist[node] + 1;
            dfs(temp);
        }
        if(vist[node] && vist[temp])
        {
           ok = true;
        }
    }
    vist[node] = 0;
//    cout << "node::" << node << endl;
}


int main()
{
    int n;
    cin >> n;
    for(int i =0;i<n;i++)
    {
        int n1,n2;
        cin >> n1 >> n2;
        v[n1].push_back(n2);
    }
    int start;
//    cin >> start;
    dfs(1);
    if(ok) cout << "cycle found." << endl;
    else cout << "cycle not found." << endl;
}
