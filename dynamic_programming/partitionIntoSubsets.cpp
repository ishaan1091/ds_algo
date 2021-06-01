#include <bits/stdc++.h>
using namespace std;

int countWaysToPartition(int n, int k)
{
    vector<vector<int>> dp(k + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= k; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (j < i)
                dp[i][j] = 0;
            else if (j == i)
                dp[i][j] = 1;
            else
                dp[i][j] = dp[i - 1][j - 1] + i * dp[i][j - 1];
        }
    }
    return dp[k][n];
}

int main()
{
    int n, k;
    cin >> n >> k;
    int ans = countWaysToPartition(n, k);
    cout << ans << endl;
    return 0;
}