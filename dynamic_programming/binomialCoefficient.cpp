#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007

int nCr(int n, int r)
{
    // code here
    vector<int> dp(r + 1, 0);
    dp[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = (i < r ? i : r); j >= 1; j--)
        {
            if (j == i)
                dp[j] = 1;
            else
                dp[j] = (dp[j] + dp[j - 1]) % mod;
        }
    }
    return dp[r];
}

int main()
{
    int n, r;
    cin >> n >> r;
    cout << nCr(n, r) << endl;
    return 0;
}