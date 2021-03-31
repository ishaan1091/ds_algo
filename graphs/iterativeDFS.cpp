#include <bits/stdc++.h>
using namespace std;

void iterativeDFS(vector<pair<int, int>> graph[], int v, int src)
{
    vector<bool> visited(v, false);
    stack<int> s;
    s.push(src);
    visited[src] = true;
    while (!s.empty())
    {
        int top = s.top();
        s.pop();
        cout << top << " ";
        for (auto vertex : graph[top])
        {
            if (!visited[vertex.first])
            {
                visited[vertex.first] = true;
                s.push(vertex.first);
            }
        }
    }
    cout << endl;
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
    int src;
    cin >> src;
    iterativeDFS(graph, v, src);
    return 0;
}