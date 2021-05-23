#include <bits/stdc++.h>
using namespace std;

int maxProfit(vector<int> &prices, int k)
{
    if (prices.size() == 0)
        return 0;
    int n = prices.size();
    vector<vector<int>> dp(k + 1, vector<int>(n, 0));
    for (int i = 1; i <= k; i++)
    {
        int maxProfit = INT_MIN;
        for (int j = 1; j < n; j++)
        {
            if (maxProfit < dp[i - 1][j - 1] - prices[j - 1])
                maxProfit = dp[i - 1][j - 1] - prices[j - 1];
            dp[i][j] = max(maxProfit + prices[j], dp[i][j - 1]);
        }
    }
    return dp[k][n - 1];
}

int main()
{
    int n;
    cin >> n;
    vector<int> prices(n);
    for (int i = 0; i < n; i++)
    {
        cin >> prices[i];
    }
    int k;
    cin >> k;
    int ans = maxProfit(prices, k);
    cout << ans << endl;
    return 0;
}