#include <bits/stdc++.h>
using namespace std;

int findByPathCompression(vector<int> &parent, int x)
{
    if (parent[x] != x)
        parent[x] = findByPathCompression(parent, parent[x]);
    return parent[x];
}

bool unionByRank(vector<int> &parent, vector<int> &rank, int x, int y)
{
    int xParent = findByPathCompression(parent, x);
    int yParent = findByPathCompression(parent, y);
    if (xParent == yParent)
        return false;
    if (rank[xParent] > rank[yParent])
    {
        parent[yParent] = xParent;
    }
    else if (rank[yParent] > rank[xParent])
    {
        parent[xParent] = yParent;
    }
    else
    {
        parent[xParent] = yParent;
        rank[yParent]++;
    }
    return true;
}

void kruskals(vector<vector<int>> &edges, int v)
{
    sort(edges.begin(), edges.end());
    vector<vector<int>> output;
    vector<int> parent(v, 0);
    vector<int> rank(v, 0);
    for (int i = 0; i < v; i++)
        parent[i] = i;
    for (auto e : edges)
    {
        bool ans = unionByRank(parent, rank, e[1], e[2]);
        if (ans)
            output.push_back(e);
    }
    for (auto e : output)
    {
        cout << min(e[1], e[2]) << " " << max(e[1], e[2]) << " " << e[0] << endl;
    }
}

int main()
{
    int v, e;
    cin >> v >> e;
    vector<vector<int>> graph;
    for (int i = 0; i < e; i++)
    {
        int src, dest, wt;
        cin >> src >> dest >> wt;
        graph.push_back({wt, src, dest});
    }
    kruskals(graph, v);
    return 0;
}