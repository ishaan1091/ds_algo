#include <bits/stdc++.h>
using namespace std;

// Here Disjoint Set has been implemented using - Union Find using Rank and Path Compression

int findUsingPathCompression(vector<int> &parent, int x)
{
    if (parent[x] != x)
    {
        parent[x] = findUsingPathCompression(parent, parent[x]);
    }
    return parent[x];
}

void unionByRank(vector<int> &parent, vector<int> &rank, int x, int y)
{
    int xParent = findUsingPathCompression(parent, x);
    int yParent = findUsingPathCompression(parent, y);
    if (xParent == yParent)
        return;
    if (rank[xParent] < rank[yParent])
    {
        parent[xParent] = yParent;
    }
    else if (rank[yParent] < rank[xParent])
    {
        parent[yParent] = xParent;
    }
    else
    {
        parent[xParent] = yParent;
        rank[yParent]++;
    }
}

void printComponents(vector<int> &parent)
{
    unordered_map<int, vector<int>> map;
    for (int i = 0; i < parent.size(); i++)
    {
        map[findUsingPathCompression(parent, i)].push_back(i);
    }
    cout << endl;
    cout << "Number of components : " << map.size() << endl;
    for (auto it : map)
    {
        cout << "Elements : ";
        for (auto i : it.second)
            cout << (char)(i + 'a') << " ";
        cout << endl;
    }
}

int main()
{
    int v, e;
    cin >> v >> e;
    vector<int> parent(v, 0);
    vector<int> rank(v, 0);
    for (int i = 0; i < v; i++)
        parent[i] = i;
    for (int i = 0; i < e; i++)
    {
        int src, dest;
        cin >> src >> dest;
        unionByRank(parent, rank, src, dest);
    }
    printComponents(parent);
    return 0;
}