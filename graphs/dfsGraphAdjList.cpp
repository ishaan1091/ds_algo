#include <bits/stdc++.h>
using namespace std;

void printDFSUtil(vector<pair<int, int>> graph[], int v, int start, bool *visited)
{
    visited[start] = true;
    cout << start << " ";
    for (auto vertex : graph[start])
    {
        if (!visited[vertex.first])
        {
            printDFSUtil(graph, v, vertex.first, visited);
        }
    }
}

void printDFS(vector<pair<int, int>> graph[], int v)
{
    bool *visited = new bool[v];
    for (int i = 0; i < v; i++)
    {
        visited[i] = false;
    }
    for (int i = 0; i < v; i++)
    {
        if (!visited[i])
        {
            printDFSUtil(graph, v, i, visited);
        }
    }
    delete[] visited;
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
    printDFS(graph, v);
    return 0;
}