#include <bits/stdc++.h>
using namespace std;

bool detectCycle(vector<int> graph[], int v)
{
    vector<int> inDegree(v, 0);
    for (int i = 0; i < v; i++)
    {
        for (auto vertex : graph[i])
        {
            inDegree[vertex]++;
        }
    }
    queue<int> q;
    int count = 0;
    for (int i = 0; i < v; i++)
    {
        if (inDegree[i] == 0)
        {
            q.push(i);
            count++;
        }
    }
    while (!q.empty())
    {
        int top = q.front();
        q.pop();
        for (auto vertex : graph[top])
        {
            if (--inDegree[vertex] == 0)
            {
                q.push(vertex);
                count++;
            }
        }
    }
    if (count != v)
    {
        return true;
    }
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
    bool ans = detectCycle(graph, v);
    cout << (ans ? "YES" : "NO") << endl;
    return 0;
}