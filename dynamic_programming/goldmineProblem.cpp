#include <bits/stdc++.h>
using namespace std;

int maxGoldPath(vector<vector<int>> &grid)
{
    vector<vector<int>> dp(grid.size(), vector<int>(grid[0].size(), 0));
    int m = grid.size();
    int n = grid[0].size();
    for (int j = n - 1; j >= 0; j--)
    {
        for (int i = m - 1; i >= 0; i--)
        {
            dp[i][j] = grid[i][j];
            int maxNum = INT_MIN;
            if (i + 1 < m && j + 1 < n)
            {
                maxNum = max(maxNum, dp[i + 1][j + 1]);
            }
            if (j + 1 < n)
            {
                maxNum = max(maxNum, dp[i][j + 1]);
            }
            if (i - 1 >= 0 && j + 1 < n)
            {
                maxNum = max(maxNum, dp[i - 1][j + 1]);
            }
            if (maxNum != INT_MIN)
            {
                dp[i][j] += maxNum;
            }
        }
    }
    int ans = INT_MIN;
    for (int i = 0; i < m; i++)
    {
        ans = max(ans, dp[i][0]);
    }
    return ans;
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
    int ans = maxGoldPath(grid);
    cout << ans << endl;
    return 0;
}