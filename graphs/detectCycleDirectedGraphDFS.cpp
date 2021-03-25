#include <bits/stdc++.h>
using namespace std;

bool isCycleUtil(vector<int> graph[], int v, int start, bool *visited, bool *currentDFS)
{
    visited[start] = true;
    currentDFS[start] = true;
    for (auto vertex : graph[start])
    {
        bool ans = false;
        if (!visited[vertex])
        {
            ans = isCycleUtil(graph, v, vertex, visited, currentDFS);
        }
        else
        {
            if (currentDFS[vertex])
            {
                ans = true;
            }
        }
        if (ans)
        {
            return true;
        }
    }
    currentDFS[start] = false;
    return false;
}

bool isCycle(int v, vector<int> graph[])
{
    bool *visited = new bool[v];
    bool *currentDFS = new bool[v];
    for (int i = 0; i < v; i++)
    {
        visited[i] = false;
    }
    for (int i = 0; i < v; i++)
    {
        currentDFS[i] = false;
    }
    for (int i = 0; i < v; i++)
    {
        bool ans = false;
        if (!visited[i])
        {
            ans = isCycleUtil(graph, v, i, visited, currentDFS);
        }
        if (ans)
        {
            delete[] visited;
            delete[] currentDFS;
            return true;
        }
    }
    delete[] visited;
    delete[] currentDFS;
    return false;
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
    bool ans = isCycle(v, graph);
    cout << (ans ? "YES" : "NO") << endl;
    return 0;
}