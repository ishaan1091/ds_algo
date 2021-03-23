#include <bits/stdc++.h>
using namespace std;

void printBFSHelper(int **edges, int n, int sv, bool *visited)
{
    queue<int> q;
    q.push(sv);
    visited[sv] = 1;
    while (!q.empty())
    {
        int top = q.front();
        q.pop();
        cout << top << " ";
        for (int i = 0; i < n; i++)
        {
            if (edges[top][i] == 1 && !visited[i])
            {
                q.push(i);
                visited[i] = 1;
            }
        }
    }
}

void printBFS(int **edges, int n)
{
    bool *visited = new bool[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = 0;
    }
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            printBFSHelper(edges, n, i, visited);
        }
    }
    delete[] visited;
}

int main()
{
    int n, e;
    cin >> n >> e;
    int **edges = new int *[n];
    for (int i = 0; i < n; i++)
    {
        edges[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            edges[i][j] = 0;
        }
    }
    for (int i = 0; i < e; i++)
    {
        int f, s;
        cin >> f >> s;
        edges[f][s] = 1;
        edges[s][f] = 1;
    }
    printBFS(edges, n);
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        delete[] edges[i];
    }
    delete[] edges;
    return 0;
}