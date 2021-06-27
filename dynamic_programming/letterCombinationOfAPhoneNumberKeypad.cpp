#include <bits/stdc++.h>
using namespace std;

int numberCombinations(int n)
{
    vector<int> dp(10, 1);
    vector<int> newDP(10, 0);
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            newDP[j] += dp[j];
            if (j % 3 != 0)
            {
                newDP[j] += dp[j + 1];
            }
            if (j != 0 && (j - 1) % 3 != 0)
            {
                newDP[j] += dp[j - 1];
            }
            if (j == 0 || j > 3)
            {
                if (j == 0)
                    newDP[j] += dp[8];
                else
                    newDP[j] += dp[j - 3];
            }
            if (j != 0 && (j == 8 || j <= 6))
            {
                if (j == 8)
                    newDP[j] += dp[0];
                else
                    newDP[j] += dp[j + 3];
            }
        }
        dp = newDP;
        fill(newDP.begin(), newDP.end(), 0);
    }
    return accumulate(dp.begin(), dp.end(), 0);
}

int main()
{
    int n;
    cin >> n;
    int ans = numberCombinations(n);
    cout << ans << endl;
    return 0;
}