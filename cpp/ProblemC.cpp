#include <bits/stdc++.h>
using namespace std;
struct Edge
{
    int src, dest, weight;
};

struct Graph
{
    int V, E;

    struct Edge* edge;
};

struct Graph* createGraph(int V, int E)
{
    struct Graph* graph = new Graph;
    graph->V = V;
    graph->E = E;
    graph->edge = new Edge[E];
    return graph;
}

void BellmanFord(struct Graph* graph, int src)
{
    int V = graph->V;
    int E = graph->E;
    int dist[V];

    for (int i = 0; i <=V; i++)
        dist[i] = INT_MAX;
    dist[src] = 0;

    for (int i = 1; i <= V ; i++)
    {
        for (int j = 0; j < E; j++)
        {
            int u = graph->edge[j].src;
            int v = graph->edge[j].dest;
            int weight = graph->edge[j].weight;
            if (dist[u] != INT_MAX && dist[u] + weight < dist[v])
                dist[v] = dist[u] + weight;
        }
    }

    for (int i = 0; i < E; i++)
    {
        int u = graph->edge[i].src;
        int v = graph->edge[i].dest;
        int weight = graph->edge[i].weight;
        if (dist[u] != INT_MAX && dist[u] + weight < dist[v])
        {
            cout << "YES,negative cycle exists." << endl;
            return;
        }
    }
    cout << "NO,there is no Negative cycle." << endl;
    return;
}

int main()
{
    int V = 5;
    int E = 5;
    struct Graph* graph = createGraph(V, E);

    graph->edge[0].src = 1;
    graph->edge[0].dest = 2;
    graph->edge[0].weight = 30;

    graph->edge[1].src = 2;
    graph->edge[1].dest = 3;
    graph->edge[1].weight = 10;

    graph->edge[2].src = 3;
    graph->edge[2].dest = 4;
    graph->edge[2].weight = 40;

    graph->edge[3].src = 5;
    graph->edge[3].dest = 4;
    graph->edge[3].weight = 20;

    graph->edge[4].src = 5;
    graph->edge[4].dest = 1;
    graph->edge[4].weight = 50;

    BellmanFord(graph, 1);

    return 0;
}


