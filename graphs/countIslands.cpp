#include <bits/stdc++.h>
using namespace std;

void traverseConnectedComponent(vector<vector<int>> &arr, int i, int j, vector<vector<bool>> &visited)
{
    if (i < 0 || j < 0 || i >= arr.size() || j >= arr[i].size() || visited[i][j] || arr[i][j] == 1)
    {
        return;
    }
    visited[i][j] = true;
    traverseConnectedComponent(arr, i - 1, j, visited);
    traverseConnectedComponent(arr, i + 1, j, visited);
    traverseConnectedComponent(arr, i, j - 1, visited);
    traverseConnectedComponent(arr, i, j + 1, visited);
}

int countIslands(vector<vector<int>> &arr)
{
    int count = 0;
    vector<vector<bool>> visited;
    for (int i = 0; i < arr.size(); i++)
    {
        vector<bool> temp;
        for (int j = 0; j < arr[i].size(); j++)
        {
            temp.push_back(false);
        }
        visited.push_back(temp);
    }
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = 0; j < arr[i].size(); j++)
        {
            if (arr[i][j] == 0 && !visited[i][j])
            {
                traverseConnectedComponent(arr, i, j, visited);
                count++;
            }
        }
    }
    return count;
}

int main()
{
    vector<vector<int>> arr;
    int m, n;
    cin >> m >> n;
    for (int i = 0; i < m; i++)
    {
        vector<int> a;
        for (int j = 0; j < n; j++)
        {
            int temp;
            cin >> temp;
            a.push_back(temp);
        }
        arr.push_back(a);
    }
    int ans = countIslands(arr);
    cout << ans << endl;
    return 0;
}