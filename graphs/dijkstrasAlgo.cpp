#include <bits/stdc++.h>
using namespace std;

void dijkstras(vector<pair<int, int>> graph[], int v, int src)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> dist(v, INT_MAX);
    dist[src] = 0;
    pq.push(make_pair(0, src));
    while (!pq.empty())
    {
        pair<int, int> minVertex = pq.top();
        pq.pop();
        for (auto i : graph[minVertex.second])
        {
            if (dist[i.first] > dist[minVertex.second] + i.second)
            {
                dist[i.first] = dist[minVertex.second] + i.second;
                pq.push(make_pair(dist[i.first], i.first));
            }
        }
    }
    for (int i = 0; i < v; i++)
    {
        cout << i << " " << dist[i] << endl;
    }
}

int main()
{
    int v, e;
    cin >> v >> e;
    vector<pair<int, int>> graph[v];
    for (int i = 0; i < e; i++)
    {
        int src, dest, wt;
        cin >> src >> dest >> wt;
        graph[src].push_back(make_pair(dest, wt));
        graph[dest].push_back(make_pair(src, wt));
    }
    int src;
    cin >> src;
    dijkstras(graph, v, src);
    return 0;
}