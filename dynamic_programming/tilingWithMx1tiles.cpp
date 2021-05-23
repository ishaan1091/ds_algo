#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007

int countWays(int n, int m)
{
    // Code here.
    vector<int> dp(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        if (i < m)
            dp[i] = 1;
        else if (i == m)
            dp[i] = 2;
        else
            dp[i] = (dp[i - 1] % mod + dp[i - m] % mod) % mod;
    }
    return dp[n];
}

int main()
{
    int n, m;
    cin >> n >> m;
    int ans = countWays(n, m);
    cout << ans << endl;
    return 0;
}