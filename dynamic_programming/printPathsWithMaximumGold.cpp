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

void printPaths(vector<vector<int>> &arr)
{
    int n = arr.size();
    int m = arr[0].size();
    vector<vector<int>> dp(n, vector<int>(m, 0));
    for (int j = m - 1; j >= 0; j--)
    {
        for (int i = n - 1; i >= 0; i--)
        {
            dp[i][j] = arr[i][j];
            int maxGold = 0;
            if (i > 0 && j < m - 1)
                maxGold = max(maxGold, dp[i - 1][j + 1]);
            if (j < m - 1)
                maxGold = max(maxGold, dp[i][j + 1]);
            if (i < n - 1 && j < m - 1)
                maxGold = max(maxGold, dp[i + 1][j + 1]);
            dp[i][j] += maxGold;
        }
    }
    int ans = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        ans = max(ans, dp[i][0]);
    }
    cout << ans << endl;
    queue<Pair> q;
    for (int i = 0; i < n; i++)
    {
        if (dp[i][0] == ans)
        {
            q.push(makePair(to_string(i), i, 0));
        }
    }
    while (!q.empty())
    {
        Pair front = q.front();
        q.pop();
        if (front.j == m - 1)
        {
            cout << front.path << endl;
            continue;
        }
        if (front.i == 0)
        {
            int greater = max(dp[front.i][front.j + 1], dp[front.i + 1][front.j + 1]);
            if (dp[front.i][front.j + 1] == greater)
            {
                q.push(makePair(front.path + " d2", front.i, front.j + 1));
            }
            if (dp[front.i + 1][front.j + 1] == greater)
            {
                q.push(makePair(front.path + " d3", front.i + 1, front.j + 1));
            }
        }
        else if (front.i == n - 1)
        {
            int greater = max(dp[front.i - 1][front.j + 1], dp[front.i][front.j + 1]);
            if (dp[front.i - 1][front.j + 1] == greater)
            {
                q.push(makePair(front.path + " d1", front.i - 1, front.j + 1));
            }
            if (dp[front.i][front.j + 1] == greater)
            {
                q.push(makePair(front.path + " d2", front.i, front.j + 1));
            }
        }
        else
        {
            int greater = max(dp[front.i - 1][front.j + 1], max(dp[front.i][front.j + 1], dp[front.i + 1][front.j + 1]));
            if (dp[front.i - 1][front.j + 1] == greater)
            {
                q.push(makePair(front.path + " d1", front.i - 1, front.j + 1));
            }
            if (dp[front.i][front.j + 1] == greater)
            {
                q.push(makePair(front.path + " d2", front.i, front.j + 1));
            }
            if (dp[front.i + 1][front.j + 1] == greater)
            {
                q.push(makePair(front.path + " d3", front.i + 1, front.j + 1));
            }
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> arr(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }
    printPaths(arr);
    return 0;
}