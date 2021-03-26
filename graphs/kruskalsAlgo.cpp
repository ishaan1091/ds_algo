#include <bits/stdc++.h>
using namespace std;

int findParent(int v, vector<int> &parent)
{
    if (parent[v] == v)
    {
        return v;
    }
    return findParent(parent[v], parent);
}

void kruskals(vector<pair<int, pair<int, int>>> &edges, int v)
{
    vector<int> parent(v);
    for (int i = 0; i < v; i++)
    {
        parent[i] = i;
    }
    sort(edges.begin(), edges.end());
    vector<pair<int, pair<int, int>>> output;
    int count = 0;
    int i = 0;
    while (count != v - 1)
    {
        pair<int, pair<int, int>> currEdge = edges[i];
        int srcParent = findParent(currEdge.second.first, parent);
        int destParent = findParent(currEdge.second.second, parent);
        if (srcParent != destParent)
        {
            output.push_back(currEdge);
            count++;
            parent[destParent] = srcParent;
        }
        i++;
    }
    for (auto edge : output)
    {
        if (edge.second.first < edge.second.second)
            cout << edge.second.first << " " << edge.second.second << " " << edge.first << endl;
        else
            cout << edge.second.second << " " << edge.second.first << " " << edge.first << endl;
    }
}

int main()
{
    int v, e;
    cin >> v >> e;
    vector<pair<int, pair<int, int>>> edges;
    for (int i = 0; i < e; i++)
    {
        int src, dest, wt;
        cin >> src >> dest >> wt;
        edges.push_back(make_pair(wt, make_pair(src, dest)));
    }
    kruskals(edges, v);
    return 0;
}