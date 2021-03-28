#include <bits/stdc++.h>
using namespace std;

pair<int, int> findParentByPathCompression(int v, vector<pair<int, int>> &parent)
{
    if (parent[v].first != v)
    {
        parent[v].first = findParentByPathCompression(parent[v].first, parent).first;
    }
    return parent[v];
}

void unionByRank(vector<pair<int, int>> &parent, pair<int, int> srcParent, pair<int, int> destParent)
{
    if (srcParent.second > destParent.second)
    {
        parent[destParent.first].first = srcParent.first;
    }
    else if (srcParent.second < destParent.second)
    {
        parent[srcParent.first].first = destParent.first;
    }
    else
    {
        parent[srcParent.first].first = destParent.first;
        parent[destParent.first].second++;
    }
}

void kruskals(vector<pair<int, pair<int, int>>> &edges, int v)
{
    vector<pair<int, int>> parent(v);
    for (int i = 0; i < v; i++)
    {
        parent[i].first = i;
        parent[i].second = 0;
    }
    sort(edges.begin(), edges.end());
    vector<pair<int, pair<int, int>>> output;
    int count = 0;
    int i = 0;
    while (count != v - 1)
    {
        pair<int, pair<int, int>> currEdge = edges[i];
        int currEdgeSrc = currEdge.second.first;
        int currEdgeDest = currEdge.second.second;
        pair<int, int> srcParent = findParentByPathCompression(currEdgeSrc, parent);
        pair<int, int> destParent = findParentByPathCompression(currEdgeDest, parent);
        if (srcParent.first != destParent.first)
        {
            output.push_back(currEdge);
            count++;
            unionByRank(parent, srcParent, destParent);
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