#include <bits/stdc++.h>
using namespace std;

int determinant(vector<vector<int>> &mat)
{
    if (mat.size() == 1)
        return mat[0][0];
    else if (mat.size() == 2)
        return mat[1][1] * mat[0][0] - mat[1][0] * mat[0][1];
    int det = 0;
    for (int k = 0; k < mat[0].size(); k++)
    {
        vector<vector<int>> tempMatrix;
        for (int i = 1; i < mat.size(); i++)
        {
            vector<int> row;
            for (int j = 0; j < mat[0].size(); j++)
            {
                if (j != k)
                {
                    row.push_back(mat[i][j]);
                }
            }
            tempMatrix.push_back(row);
        }
        det += pow(-1, k) * mat[0][k] * determinant(tempMatrix);
    }
    return det;
}

int totalSpanningTrees(vector<vector<int>> &graph, int v)
{
    for (int i = 0; i < v; i++)
    {
        graph[i][i] = count(graph[i].begin(), graph[i].end(), 1);
    }
    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < v; j++)
        {
            if (graph[i][j] == 1 && i != j)
                graph[i][j] = -1;
        }
    }
    vector<vector<int>> subMatrix(v - 1, vector<int>(v - 1, 0));
    for (int i = 1; i < v; i++)
    {
        for (int j = 1; j < v; j++)
        {
            subMatrix[i - 1][j - 1] = graph[i][j];
        }
    }
    return determinant(subMatrix);
}

int main()
{
    int v, e;
    cin >> v >> e;
    vector<vector<int>> graph(v, vector<int>(v, 0));
    for (int i = 0; i < e; i++)
    {
        int src, dest;
        cin >> src >> dest;
        graph[src][dest] = 1;
        graph[dest][src] = 1;
    }
    int ans = totalSpanningTrees(graph, v);
    cout << ans << endl;
    return 0;
}