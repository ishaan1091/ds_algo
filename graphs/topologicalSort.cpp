#include <bits/stdc++.h>
using namespace std;

void topologicalSortUtil(vector<int> graph[], int v, int src, vector<bool> &visited, stack<int> &s)
{
    visited[src] = true;
    for (auto i : graph[src])
    {
        if (!visited[i])
        {
            topologicalSortUtil(graph, v, i, visited, s);
        }
    }
    s.push(src);
}

void topologicalSort(vector<int> graph[], int v)
{
    vector<bool> visited(v, false);
    stack<int> s;
    for (int i = 0; i < v; i++)
    {
        if (!visited[i])
        {
            topologicalSortUtil(graph, v, i, visited, s);
        }
    }
    while (!s.empty())
    {
        cout << s.top() << endl;
        s.pop();
    }
}

int main()
{
    int v, e;
    cin >> v >> e;
    vector<int> graph[v];
    for (int i = 0; i < e; i++)
    {
        int src, dest;
        cin >> src >> dest;
        graph[src].push_back(dest);
    }
    topologicalSort(graph, v);
    return 0;
}