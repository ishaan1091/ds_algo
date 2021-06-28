#include <bits/stdc++.h>
using namespace std;

bool isValid(int n, int r, int c)
{
    if (r < n && c < n && c >= 0 && r >= 0)
        return true;
    return false;
}

double knightProbability(int n, int k, int r, int c)
{
    vector<vector<double>> dp(n, vector<double>(n, 0));
    dp[r][c] = 1;
    vector<int> ivals = {2, 1, -1, -2, -2, -1, 1, 2};
    vector<int> jvals = {1, 2, 2, 1, -1, -2, -2, -1};
    for (int iter = 0; iter < k; iter++)
    {
        vector<vector<double>> newDP(n, vector<double>(n, 0));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (dp[i][j])
                {
                    for (int k = 0; k < 8; k++)
                    {
                        if (isValid(n, i + ivals[k], j + jvals[k]))
                            newDP[i + ivals[k]][j + jvals[k]] += dp[i][j] / 8.0;
                    }
                }
            }
        }
        dp = newDP;
    }
    double sum = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            sum += dp[i][j];
    return sum;
}

int main()
{
    int n, k, r, c;
    cin >> n >> k >> r >> c;
    double ans = knightProbability(n, k, r, c);
    cout << ans << endl;
    return 0;
}