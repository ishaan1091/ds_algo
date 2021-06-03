#include <bits/stdc++.h>
using namespace std;

class Pair
{
public:
    string path;
    int i;
    int j;
};

Pair makePair(string path, int i, int j)
{
    Pair p;
    p.path = path;
    p.i = i;
    p.j = j;
    return p;
}

void printAllMinCostPaths(vector<vector<int>> &arr)
{
    vector<vector<int>> dp(arr.size(), vector<int>(arr[0].size(), 0));
    for (int i = arr.size() - 1; i >= 0; i--)
    {
        for (int j = arr[0].size() - 1; j >= 0; j--)
        {
            if (i == arr.size() - 1 && j == arr[0].size() - 1)
            {
                dp[i][j] = arr[i][j];
            }
            else if (i == arr.size() - 1)
            {
                dp[i][j] = dp[i][j + 1] + arr[i][j];
            }
            else if (j == arr[0].size() - 1)
            {
                dp[i][j] = dp[i + 1][j] + arr[i][j];
            }
            else
            {
                dp[i][j] = min(dp[i + 1][j], dp[i][j + 1]) + arr[i][j];
            }
        }
    }
    cout << dp[0][0] << endl;
    queue<Pair> q;
    q.push(makePair("", 0, 0));
    while (!q.empty())
    {
        Pair front = q.front();
        q.pop();
        if (front.i == arr.size() - 1 && front.j == arr[0].size() - 1)
        {
            cout << front.path << endl;
        }
        else if (front.i == arr.size() - 1)
        {
            q.push(makePair(front.path + "H", front.i, front.j + 1));
        }
        else if (front.j == arr[0].size() - 1)
        {
            q.push(makePair(front.path + "V", front.i + 1, front.j));
        }
        else
        {
            if (dp[front.i + 1][front.j] <= dp[front.i][front.j + 1])
            {
                q.push(makePair(front.path + "V", front.i + 1, front.j));
            }
            if (dp[front.i + 1][front.j] >= dp[front.i][front.j + 1])
            {
                q.push(makePair(front.path + "H", front.i, front.j + 1));
            }
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> arr(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }
    printAllMinCostPaths(arr);
    return 0;
}