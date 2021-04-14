#include <bits/stdc++.h>
using namespace std;

bool isGraphBipartiteUtil(vector<int> graph[], int v, int start, vector<int> &visited)
{
    queue<pair<int, int>> q;
    q.push(make_pair(start, 0));
    while (!q.empty())
    {
        pair<int, int> front = q.front();
        if (visited[front.first] == -1)
        {
            visited[front.first] = front.second;
        }
        else
        {
            if (front.second != visited[front.first])
            {
                return false;
            }
        }
        q.pop();
        for (auto vertex : graph[front.first])
        {
            if (visited[vertex] == -1)
            {
                q.push(make_pair(vertex, front.second + 1));
            }
        }
    }
    return true;
}

bool isGraphBipartite(vector<int> graph[], int v)
{
    vector<int> visited(v, -1);
    for (int i = 0; i < v; i++)
    {
        if (visited[i] == -1)
        {
            if (!isGraphBipartiteUtil(graph, v, i, visited))
            {
                return false;
            }
        }
    }
    return true;
}

int main()
{
    int v, e;
    cin >> v >> e;
    vector<int> graph[v];
    for (int i = 0; i < e; i++)
    {
        int src, dest, wt;
        cin >> src >> dest >> wt;
        graph[src].push_back(dest);
        graph[dest].push_back(src);
    }
    cout << (isGraphBipartite(graph, v) ? "YES" : "NO") << endl;
    return 0;
}