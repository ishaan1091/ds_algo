#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>> &graph, int n, int sv, int start, vector<bool> &visited, int &count)
{
    if (n == 0)
    {
        if (graph[sv][start])
            count++;
        return;
    }
    visited[sv] = true;
    for (int i = 0; i < graph.size(); i++)
    {
        if (graph[sv][i] && !visited[i])
            dfs(graph, n - 1, i, start, visited, count);
    }
    visited[sv] = false;
}

int countCycle(vector<vector<int>> &graph, int n)
{
    int v = graph.size();
    vector<bool> visited(v, false);
    int count = 0;
    for (int i = 0; i < v; i++)
    {
        if (!visited[i])
            dfs(graph, n - 1, i, i, visited, count);
    }
    return count / (2 * n);
}

int main()
{
    // Write your code here
    int v, e;
    cin >> v >> e;
    vector<vector<int>> graph(v, vector<int>(v, 0));
    for (int i = 0; i < e; i++)
    {
        int src, dest;
        cin >> src >> dest;
        graph[src][dest] = 1;
        graph[dest][src] = 1;
    }
    int ans = countCycle(graph, 4);
    cout << ans << endl;
    return 0;
}