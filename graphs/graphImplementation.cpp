#include <bits/stdc++.h>
using namespace std;

void printGraph(vector<pair<int, int>> graph[], int v)
{
    for (int i = 0; i < v; i++)
    {
        cout << "Node " << i << " has edge with - " << endl;
        for (auto w : graph[i])
        {
            cout << "\tNode " << w.first << " with weight " << w.second << endl;
        }
        cout << endl;
    }
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
    printGraph(graph, v);
    return 0;
}