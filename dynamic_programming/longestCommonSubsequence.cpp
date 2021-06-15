#include <bits/stdc++.h>
using namespace std;

int longestCommonSubsequence(string s, string t)
{
    int n = s.length();
    int m = t.length();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = m - 1; j >= 0; j--)
        {
            if (s[i] == t[j])
            {
                dp[i][j] = 1 + dp[i + 1][j + 1];
            }
            else
            {
                dp[i][j] = max(dp[i + 1][j], dp[i][j + 1]);
            }
        }
    }
    return dp[0][0];
}

int main()
{
    string s, t;
    cin >> s >> t;
    int ans = longestCommonSubsequence(s, t);
    cout << ans << endl;
    return 0;
}