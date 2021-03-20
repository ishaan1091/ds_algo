#include <bits/stdc++.h>
using namespace std;

bool hasPath(vector<pair<int, int>> graph[], int v, int src, int dest, bool *visited)
{
    if (src == dest)
    {
        return true;
    }
    visited[src] = true;
    for (auto nbr : graph[src])
    {
        if (!visited[nbr.first])
        {
            bool hasNbrPath = hasPath(graph, v, nbr.first, dest, visited);
            if (hasNbrPath)
            {
                return true;
            }
        }
    }
    return false;
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
    int src, dest;
    cin >> src >> dest;
    bool *visited = new bool[v];
    for (int i = 0; i < v; i++)
    {
        visited[i] = 0;
    }
    bool path = hasPath(graph, v, src, dest, visited);
    cout << (path ? "Yes" : "No") << endl;
    delete[] visited;
    return 0;
}