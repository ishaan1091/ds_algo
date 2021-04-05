#include <bits/stdc++.h>
using namespace std;

int minPathSum(vector<vector<int>> &grid)
{
    vector<vector<int>> dp(grid.size(), vector<int>(grid[0].size(), 0));
    int m = grid.size();
    int n = grid[0].size();
    for (int i = m - 1; i >= 0; i--)
    {
        for (int j = n - 1; j >= 0; j--)
        {
            dp[i][j] = grid[i][j];
            int minNum = INT_MAX;
            if (j + 1 < n)
            {
                minNum = min(minNum, dp[i][j + 1]);
            }
            if (i + 1 < m)
            {
                minNum = min(minNum, dp[i + 1][j]);
            }
            if (minNum != INT_MAX)
            {
                dp[i][j] += minNum;
            }
        }
    }
    return dp[0][0];
}

int main()
{
    int m, n;
    cin >> m >> n;
    vector<vector<int>> grid(m, vector<int>(n));
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> grid[i][j];
        }
    }
    int ans = minPathSum(grid);
    cout << ans << endl;
    return 0;
}