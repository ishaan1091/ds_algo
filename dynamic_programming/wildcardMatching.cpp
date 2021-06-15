#include <bits/stdc++.h>
using namespace std;

bool isMatch(string s, string p)
{
    vector<vector<bool>> dp(p.length() + 1, vector<bool>(s.length() + 1, 0));
    dp[p.length()][s.length()] = true;
    for (int i = dp.size() - 2; i >= 0; i--)
    {
        for (int j = dp[0].size() - 1; j >= 0; j--)
        {
            if (j == dp[0].size() - 1)
            {
                if (p[i] == '*')
                {
                    dp[i][j] = dp[i + 1][j];
                }
            }
            else if (p[i] == '?')
            {
                dp[i][j] = dp[i + 1][j + 1];
            }
            else if (p[i] == '*')
            {
                dp[i][j] = (dp[i + 1][j] ? dp[i + 1][j] : dp[i][j + 1]);
            }
            else
            {
                if (p[i] == s[j])
                {
                    dp[i][j] = dp[i + 1][j + 1];
                }
            }
        }
    }
    return dp[0][0];
}

int main()
{
    string s, p;
    cin >> s >> p;
    cout << (isMatch(s, p) ? "YES" : "NO") << endl;
    return 0;
}