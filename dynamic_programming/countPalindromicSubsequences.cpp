#include <bits/stdc++.h>
using namespace std;

int countSubsequences(string s)
{
    vector<vector<int>> dp(s.length(), vector<int>(s.length(), 0));
    for (int g = 0; g < s.length(); g++)
    {
        for (int i = 0, j = g; j < s.length(); i++, j++)
        {
            if (g == 0)
                dp[i][j] = 1;
            else if (g == 1)
            {
                if (s[i] == s[j])
                    dp[i][j] = 3;
                else
                    dp[i][j] = 2;
            }
            else
            {
                if (s[i] == s[j])
                {
                    dp[i][j] = dp[i][j - 1] + dp[i + 1][j] + 1;
                }
                else
                {
                    dp[i][j] = dp[i][j - 1] + dp[i + 1][j] - dp[i + 1][j - 1];
                }
            }
        }
    }
    return dp[0][s.length() - 1];
}

int main()
{
    string s;
    cin >> s;
    int ans = countSubsequences(s);
    cout << ans << endl;
    return 0;
}