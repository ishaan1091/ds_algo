#include <bits/stdc++.h>
using namespace std;

void printBFSHelper(vector<pair<int, int>> graph[], int v, int start, bool *visited)
{
    queue<int> q;
    q.push(start);
    visited[start] = true;
    while (!q.empty())
    {
        int front = q.front();
        cout << front << " ";
        q.pop();
        for (auto i : graph[front])
        {
            if (!visited[i.first])
            {
                visited[i.first] = true;
                q.push(i.first);
            }
        }
    }
}

void printBFS(vector<pair<int, int>> graph[], int v)
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
            printBFSHelper(graph, v, i, visited);
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
    printBFS(graph, v);
    return 0;
}