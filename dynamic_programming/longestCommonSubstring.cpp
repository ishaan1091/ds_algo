#include <bits/stdc++.h>
using namespace std;

int longestCommonSubstring(string s, string t)
{
    vector<vector<int>> dp(s.length() + 1, vector<int>(t.length() + 1, 0));
    int ans = 0;
    for (int i = s.length() - 1; i >= 0; i--)
    {
        for (int j = t.length() - 1; j >= 0; j--)
        {
            if (s[i] == t[j])
                dp[i][j] = 1 + dp[i + 1][j + 1];
            ans = max(dp[i][j], ans);
        }
    }
    return ans;
}

int main()
{
    string s, t;
    cin >> s >> t;
    int ans = longestCommonSubstring(s, t);
    cout << ans << endl;
    return 0;
}