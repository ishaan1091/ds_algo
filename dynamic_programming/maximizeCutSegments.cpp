#include <bits/stdc++.h>
using namespace std;

int maximizeTheCuts(int n, int x, int y, int z)
{
    //Your code here
    vector<int> dp(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        if (i >= x)
        {
            if (dp[i - x] || i - x == 0)
                dp[i] = max(dp[i - x] + 1, dp[i]);
        }
        if (i >= y)
        {
            if (dp[i - y] || i - y == 0)
                dp[i] = max(dp[i - y] + 1, dp[i]);
        }
        if (i >= z)
        {
            if (dp[i - z] || i - z == 0)
                dp[i] = max(dp[i - z] + 1, dp[i]);
        }
    }
    return dp[n];
}

int main()
{
    int n, x, y, z;
    cin >> n >> x >> y >> z;
    int ans = maximizeTheCuts(n, x, y, z);
    cout << ans << endl;
    return 0;
}