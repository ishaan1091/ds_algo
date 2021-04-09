#include <bits/stdc++.h>
using namespace std;

void printDFSUtil(vector<int> graph[], int v, int start, vector<bool> &visited)
{
    visited[start] = true;
    cout << start << " ";
    for (auto vertex : graph[start])
    {
        if (!visited[vertex])
        {
            printDFSUtil(graph, v, vertex, visited);
        }
    }
}

void transpose(vector<int> graph[], int v, vector<int> newGraph[])
{
    for (int i = 0; i < v; i++)
    {
        for (auto vertex : graph[i])
        {
            newGraph[vertex].push_back(i);
        }
    }
}

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

void stronglyConnectedComponents(vector<int> graph[], int v)
{
    vector<bool> visited(v, false);
    stack<int> s;
    // Calling DFS for the first time
    for (int i = 0; i < v; i++)
    {
        if (!visited[i])
        {
            topologicalSortUtil(graph, v, i, visited, s);
        }
    }

    // Transposing or Reversing the graph
    vector<int> newGraph[v];
    transpose(graph, v, newGraph);

    // Calling DFS on stack elements in the reversed/transposed graph
    for (int i = 0; i < v; i++)
    {
        visited[i] = false;
    }
    while (!s.empty())
    {
        int top = s.top();
        s.pop();
        if (!visited[top])
        {
            printDFSUtil(newGraph, v, top, visited);
            cout << endl;
        }
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
    stronglyConnectedComponents(graph, v);
    return 0;
}