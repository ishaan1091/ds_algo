#include <bits/stdc++.h>
using namespace std;

void floydWarshall(vector<pair<int, int>> graph[], int v)
{
    vector<vector<int>> dist(v, vector<int>(v, INT_MAX));
    for (int i = 0; i < v; i++)
    {
        dist[i][i] = 0;
    }
    for (int i = 0; i < v; i++)
    {
        for (auto vertex : graph[i])
        {
            dist[i][vertex.first] = vertex.second;
        }
    }
    for (int k = 0; k < v; k++)
    {
        for (int i = 0; i < v; i++)
        {
            for (int j = 0; j < v; j++)
            {
                if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX && dist[i][k] + dist[k][j] < dist[i][j])
                {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < v; j++)
        {
            if (dist[i][j] == INT_MAX)
            {
                cout << "-1"
                     << "     ";
            }
            else
            {
                cout << dist[i][j] << "     ";
            }
        }
        cout << endl;
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
    }
    floydWarshall(graph, v);
    return 0;
}