#include <bits/stdc++.h>
using namespace std;

void allPaths(vector<pair<int, int>> graph[], int v, bool *visited, int src, int dest, string path)
{
    if (src == dest)
    {
        cout << path << endl;
        return;
    }
    visited[src] = true;
    for (auto e : graph[src])
    {
        if (!visited[e.first])
        {
            allPaths(graph, v, visited, e.first, dest, path + to_string(e.first));
        }
    }
    visited[src] = false;
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
    allPaths(graph, v, visited, src, dest, to_string(src) + "");
    delete[] visited;
    return 0;
}