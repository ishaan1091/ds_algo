#include <bits/stdc++.h>
using namespace std;

int optCost(vector<int> &freq)
{
    int n = freq.size();
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    for (int g = 1; g <= n; g++)
    {
        for (int i = 0, j = g; j <= n; i++, j++)
        {
            if (g == 1)
                dp[i][j] = freq[i];
            else
            {
                int minCost = INT_MAX;
                int freqSum = 0;
                for (int k = i; k < j; k++)
                {
                    freqSum += freq[k];
                    minCost = min(minCost, dp[i][k] + dp[k + 1][j]);
                }
                dp[i][j] = freqSum + minCost;
            }
        }
    }
    return dp[0][n];
}

int main()
{
    int n;
    cin >> n;
    vector<int> freq(n);
    for (int i = 0; i < n; i++)
        cin >> freq[i];
    int ans = optCost(freq);
    cout << ans << endl;
    return 0;
}