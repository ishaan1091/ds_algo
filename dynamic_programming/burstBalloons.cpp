#include <bits/stdc++.h>
using namespace std;

int maxCoins(vector<int> &nums)
{
    int n = nums.size();
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    for (int g = 1; g <= n; g++)
    {
        for (int i = 0, j = g; j <= n; i++, j++)
        {
            int maxProfit = 0;
            for (int k = i; k < j; k++)
            {
                int lastBalloon = nums[k];
                if (i > 0)
                    lastBalloon *= nums[i - 1];
                if (j < n)
                    lastBalloon *= nums[j];
                maxProfit = max(maxProfit, dp[i][k] + lastBalloon + dp[k + 1][j]);
            }
            dp[i][j] = maxProfit;
        }
    }
    return dp[0][n];
}

int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];
    int ans = maxCoins(nums);
    cout << ans << endl;
    return 0;
}