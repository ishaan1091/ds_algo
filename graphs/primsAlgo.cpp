#include <bits/stdc++.h>
using namespace std;

void prims(vector<pair<int, int>> graph[], int v)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<bool> visited(v, false);
    vector<int> weights(v, INT_MAX);
    vector<int> parents(v, -1);
    weights[0] = 0;
    int src = 0;
    pq.push(make_pair(0, src));
    while (!pq.empty())
    {
        pair<int, int> minWeightVertex = pq.top();
        pq.pop();
        visited[minWeightVertex.second] = true;
        for (auto i : graph[minWeightVertex.second])
        {
            if (!visited[i.first])
            {
                if (weights[i.first] > i.second)
                {
                    parents[i.first] = minWeightVertex.second;
                    weights[i.first] = i.second;
                    pq.push(make_pair(i.second, i.first));
                }
            }
        }
    }
    for (int i = 1; i < v; i++)
    {
        cout << "[" << i << "-" << parents[i] << "@" << weights[i] << "]" << endl;
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
    prims(graph, v);
    return 0;
}