#include <bits/stdc++.h>
using namespace std;

vector<int> getConnectedUtils(vector<pair<int, int>> graph[], int v, bool *visited, int start)
{
    vector<int> output;
    visited[start] = true;
    output.push_back(start);
    for (auto vertex : graph[start])
    {
        if (!visited[vertex.first])
        {
            vector<int> ans = getConnectedUtils(graph, v, visited, vertex.first);
            output.insert(output.end(), ans.begin(), ans.end());
        }
    }
    return output;
}

vector<vector<int>> getConnected(vector<pair<int, int>> graph[], int v)
{
    vector<vector<int>> ans;
    bool *visited = new bool[v];
    for (int i = 0; i < v; i++)
    {
        visited[i] = 0;
    }
    for (int i = 0; i < v; i++)
    {
        if (!visited[i])
        {
            ans.push_back(getConnectedUtils(graph, v, visited, i));
        }
    }
    delete[] visited;
    return ans;
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
    vector<vector<int>> output = getConnected(graph, v);
    for (auto vec : output)
    {
        for (auto i : vec)
        {
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}