#include <bits/stdc++.h>
using namespace std;

string largestPath = "";
string shortestPath = "";
string justLargerPath = "";
string justShorterPath = "";
int largestPathWt = INT_MIN, shortestPathWt = INT_MAX, justLargerPathWt = INT_MAX, justShorterPathWt = INT_MIN;
priority_queue<pair<int, string>, vector<pair<int, string>>, greater<pair<int, string>>> pq;

void multisolverPaths(vector<pair<int, int>> graph[], int v, bool *visited, int src, int dest, int criteria, int k, string path, int weight)
{
    if (src == dest)
    {
        if (weight < shortestPathWt)
        {
            shortestPath = path;
            shortestPathWt = weight;
        }
        if (weight > largestPathWt)
        {
            largestPath = path;
            largestPathWt = weight;
        }
        if (weight < criteria && weight > justShorterPathWt)
        {
            justShorterPath = path;
            justShorterPathWt = weight;
        }
        if (weight > criteria && weight < justLargerPathWt)
        {
            justLargerPath = path;
            justLargerPathWt = weight;
        }
        if (pq.size() < k)
        {
            pq.push(make_pair(weight, path));
        }
        else
        {
            if (pq.top().first < weight)
            {
                pq.pop();
                pq.push(make_pair(weight, path));
            }
        }
    }
    visited[src] = true;
    for (auto e : graph[src])
    {
        if (!visited[e.first])
        {
            multisolverPaths(graph, v, visited, e.first, dest, criteria, k, path + to_string(e.first), weight + e.second);
        }
    }
    visited[src] = false;
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
    int src, dest, criteria, k;
    cin >> src >> dest >> criteria >> k;
    bool *visited = new bool[v];
    for (int i = 0; i < v; i++)
    {
        visited[i] = 0;
    }
    multisolverPaths(graph, v, visited, src, dest, criteria, k, to_string(src) + "", 0);
    cout << "Largest Path : " << largestPath << " having weight " << largestPathWt << endl;
    cout << "Shortest Path : " << shortestPath << " having weight " << shortestPathWt << endl;
    cout << "Just Larger Path than " << criteria << " : " << justLargerPath << " having weight " << justLargerPathWt << endl;
    cout << "Just Shorter Path than " << criteria << " : " << justShorterPath << " having weight " << justShorterPathWt << endl;
    cout << k << "th Largest Path : " << pq.top().second << " having weight " << pq.top().first << endl;
    delete[] visited;
    return 0;
}