#include <bits/stdc++.h>
using namespace std;

int countPalindromicSubsequences(string s)
{
    int n = s.length();
    unordered_map<char, int> map;
    vector<int> prev(n, -1);
    for (int i = 0; i < n; i++)
    {
        if (map.count(s[i]))
        {
            prev[i] = map[s[i]];
        }
        map[s[i]] = i;
    }
    map.clear();
    vector<int> next(n, -1);
    for (int i = n - 1; i >= 0; i--)
    {
        if (map.count(s[i]))
        {
            next[i] = map[s[i]];
        }
        map[s[i]] = i;
    }
    vector<vector<int>> dp(s.length(), vector<int>(s.length(), 0));
    for (int g = 0; g < n; g++)
    {
        for (int i = 0, j = g + i; j < n; i++, j++)
        {
            if (g == 0)
            {
                dp[i][j] = 1;
            }
            else if (g == 1)
            {
                dp[i][j] = 2;
            }
            else
            {
                if (s[i] != s[j])
                {
                    dp[i][j] = dp[i][j - 1] + dp[i + 1][j] - dp[i + 1][j - 1];
                }
                else
                {
                    dp[i][j] = 2 * dp[i + 1][j - 1];
                    if (next[i] < prev[j])
                    {
                        dp[i][j] -= dp[next[i] + 1][prev[j] - 1];
                    }
                    else if (next[i] == prev[j])
                    {
                        dp[i][j] += 1;
                    }
                    else
                    {
                        dp[i][j] += 2;
                    }
                }
            }
        }
    }
    return dp[0][n - 1];
}

int main()
{
    string s;
    cin >> s;
    int ans = countPalindromicSubsequences(s);
    cout << ans << endl;
    return 0;
}