#include <bits/stdc++.h>
using namespace std;

int minCut(string s)
{
    int n = s.length();
    vector<vector<bool>> dp(n, vector<bool>(n, 0));
    for (int g = 0; g < n; g++)
    {
        for (int i = 0, j = i + g; j < n; i++, j++)
        {
            if (g == 0)
            {
                dp[i][j] = true;
            }
            else if (g == 1)
            {
                dp[i][j] = s[i] == s[j];
            }
            else
            {
                dp[i][j] = (s[i] == s[j] && dp[i + 1][j - 1]);
            }
        }
    }
    vector<int> dp2(n, 0);
    for (int i = 1; i < n; i++)
    {
        if (!dp[0][i])
        {
            int minCuts = INT_MAX;
            for (int j = i; j >= 1; j--)
            {
                if (dp[j][i])
                {
                    minCuts = min(minCuts, 1 + dp2[j - 1]);
                }
            }
            dp2[i] = minCuts;
        }
    }
    return dp2[n - 1];
}

int main()
{
    string s;
    cin >> s;
    int ans = minCut(s);
    cout << ans << endl;
    return 0;
}