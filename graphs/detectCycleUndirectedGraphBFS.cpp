#include <bits/stdc++.h>
using namespace std;

bool isCycleUtil(vector<int> graph[], int v, int start, bool *visited)
{
    queue<pair<int, int>> q;
    q.push(make_pair(start, -1));
    visited[start] = true;
    while (!q.empty())
    {
        pair<int, int> front = q.front();
        q.pop();
        for (auto i : graph[front.first])
        {
            if (!visited[i])
            {
                visited[i] = true;
                q.push(make_pair(i, front.first));
            }
            else
            {
                if (i != front.second)
                {
                    return true;
                }
            }
        }
    }
    return false;
}

bool isCycle(int v, vector<int> graph[])
{
    bool *visited = new bool[v];
    for (int i = 0; i < v; i++)
    {
        visited[i] = false;
    }
    for (int i = 0; i < v; i++)
    {
        bool ans = false;
        if (!visited[i])
        {
            ans = isCycleUtil(graph, v, i, visited);
        }
        if (ans)
        {
            delete[] visited;
            return true;
        }
    }
    delete[] visited;
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
        graph[dest].push_back(src);
    }
    bool ans = isCycle(v, graph);
    cout << (ans ? "YES" : "NO") << endl;
    return 0;
}