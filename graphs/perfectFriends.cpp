#include <bits/stdc++.h>
using namespace std;

vector<int> getConnectedUtils(vector<int> graph[], int v, bool *visited, int start)
{
    vector<int> output;
    visited[start] = true;
    output.push_back(start);
    for (auto vertex : graph[start])
    {
        if (!visited[vertex])
        {
            vector<int> ans = getConnectedUtils(graph, v, visited, vertex);
            output.insert(output.end(), ans.begin(), ans.end());
        }
    }
    return output;
}

vector<vector<int>> getConnected(vector<int> graph[], int v)
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

int perfectFriends(vector<int> graph[], int v)
{
    vector<vector<int>> output = getConnected(graph, v);
    int sum = 0;
    for (int i = 0; i < output.size(); i++)
    {
        for (int j = i + 1; j < output.size(); j++)
        {
            sum += output[i].size() * output[j].size();
        }
    }
    return sum;
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
    int ans = perfectFriends(graph, v);
    cout << ans << endl;
    return 0;
}