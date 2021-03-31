#include <bits/stdc++.h>
using namespace std;

void bellmanFord(vector<pair<int, pair<int, int>>> &edges, int v, int src)
{
    vector<int> dist(v, INT_MAX);
    dist[src] = 0;

    for (int i = 0; i < v - 1; i++)
    {
        for (int j = 0; j < edges.size(); j++)
        {
            int edgeSrc = edges[j].first;
            int edgeDest = edges[j].second.first;
            int edgeWeight = edges[j].second.second;
            if (dist[edgeSrc] != INT_MAX && dist[edgeSrc] + edgeWeight < dist[edgeDest])
            {
                dist[edgeDest] = dist[edgeSrc] + edgeWeight;
            }
        }
    }

    for (int j = 0; j < edges.size(); j++)
    {
        int edgeSrc = edges[j].first;
        int edgeDest = edges[j].second.first;
        int edgeWeight = edges[j].second.second;
        if (dist[edgeSrc] != INT_MAX && dist[edgeSrc] + edgeWeight < dist[edgeDest])
        {
            cout << "Negative Cycle present" << endl;
            return;
        }
    }

    for (int i = 0; i < v; i++)
    {
        cout << i << "  " << dist[i] << endl;
    }
}

int main()
{
    int v, e;
    cin >> v >> e;
    vector<pair<int, pair<int, int>>> edges;
    for (int i = 0; i < e; i++)
    {
        int src, dest, wt;
        cin >> src >> dest >> wt;
        edges.push_back(make_pair(src, make_pair(dest, wt)));
    }
    int src;
    cin >> src;
    bellmanFord(edges, v, src);
    return 0;
}