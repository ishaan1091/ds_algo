#include <bits/stdc++.h>
using namespace std;

string longestPalindromicSubstring(string s)
{
    vector<vector<bool>> dp(s.length(), vector<bool>(s.length(), 0));
    string ans = "";
    for (int g = 0; g < s.length(); g++)
    {
        for (int i = 0, j = g; true; i++, j++)
        {
            if (j == s.length())
                break;
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
                dp[i][j] = s[i] == s[j] && dp[i + 1][j - 1];
            }
            if (dp[i][j] && ans.length() < g + 1)
                ans = s.substr(i, j - i + 1);
        }
    }
    return ans;
}

int main()
{
    string s;
    cin >> s;
    string ans = longestPalindromicSubstring(s);
    cout << ans << endl;
    return 0;
}