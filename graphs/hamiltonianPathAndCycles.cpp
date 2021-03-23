#include <bits/stdc++.h>
using namespace std;

void printHamiltonian(vector<int> graph[], int v, int src, string path, unordered_set<int> visited, int original_src)
{
    if (visited.size() == v - 1)
    {
        cout << path;
        for (auto vertex : graph[src])
        {
            if (vertex == original_src)
            {
                cout << "*" << endl;
                return;
            }
        }
        cout << "." << endl;
        return;
    }
    visited.insert(src);
    for (auto vertex : graph[src])
    {
        if (visited.find(vertex) == visited.end())
        {
            printHamiltonian(graph, v, vertex, path + to_string(vertex), visited, original_src);
        }
    }
    visited.erase(src);
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
    int src;
    cin >> src;
    unordered_set<int> visited;
    printHamiltonian(graph, v, src, to_string(src) + "", visited, src);
    return 0;
}