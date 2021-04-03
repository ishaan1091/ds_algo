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
        cout << (char)(s.top() + 97) << endl;
        s.pop();
    }
}

void findOrder(string dict[], int n, int k)
{
    vector<int> graph[k];
    for (int i = 0; i < n - 1; i++)
    {
        string a = dict[i];
        string b = dict[i + 1];
        for (int j = 0; j < min(a.length(), b.length()); j++)
        {
            if (a[j] != b[j])
            {
                graph[a[j] - 97].push_back(b[j] - 97);
                break;
            }
        }
    }
    topologicalSort(graph, k);
}

int main()
{
    int n, k;
    cin >> n >> k;
    string *dict = new string[n];
    for (int i = 0; i < n; i++)
    {
        cin >> dict[i];
    }
    findOrder(dict, n, k);
    delete[] dict;
    return 0;
}