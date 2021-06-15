#include <bits/stdc++.h>
using namespace std;

// Recursion
bool isMatchRec(string s, string p)
{
    if (p.length() == 0)
        return s.length() == 0;
    bool start = s.length() > 0 && (s[0] == p[0] || p[0] == '.');
    if (p.length() >= 2 && p[1] == '*')
    {
        return isMatchRec(s, p.substr(2)) || (start && isMatchRec(s.substr(1), p));
    }
    return start && isMatchRec(s.substr(1), p.substr(1));
}

// Memoization
bool isMatchHelper(string s, string p, int i, int j, vector<vector<int>> &dp)
{
    if (i == p.length())
        return j == s.length();
    if (i < dp.size() && j < dp[0].size() && dp[i][j] != -1)
        return dp[i][j];
    bool start = j < s.length() && (s[j] == p[i] || p[i] == '.');
    if (p.length() - 2 >= i && p[i + 1] == '*')
    {
        bool ans = isMatchHelper(s, p, i + 2, j, dp) || (start && isMatchHelper(s, p, i, j + 1, dp));
        dp[i][j] = ans;
        return ans;
    }
    bool ans = start && isMatchHelper(s, p, i + 1, j + 1, dp);
    dp[i][j] = ans;
    return ans;
}

bool isMatchMem(string s, string p)
{
    vector<vector<int>> mem(p.length(), vector<int>(s.length() + 1, -1));
    bool ans = isMatchHelper(s, p, 0, 0, mem);
    return ans;
}

// Dynamic Programming
bool isMatchDP(string s, string p)
{
    vector<vector<bool>> dp(p.length() + 1, vector<bool>(s.length() + 1, 0));
    for (int i = 0; i < dp.size(); i++)
    {
        for (int j = 0; j < dp[0].size(); j++)
        {
            if (i == 0 && j == 0)
            {
                dp[i][j] = true;
            }
            else if (i == 0)
            {
                dp[i][j] = false;
            }
            else if (j == 0)
            {
                if (p[i - 1] == '*')
                {
                    dp[i][j] = dp[i - 2][j];
                }
                else
                {
                    dp[i][j] = false;
                }
            }
            else
            {
                if (p[i - 1] == '.')
                {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else if (p[i - 1] == '*')
                {
                    dp[i][j] = dp[i - 2][j] || ((p[i - 2] == s[j - 1] || p[i - 2] == '.') && dp[i][j - 1]);
                }
                else
                {
                    if (p[i - 1] == s[j - 1])
                        dp[i][j] = dp[i - 1][j - 1];
                    else
                        dp[i][j] = false;
                }
            }
        }
    }
    return dp[p.length()][s.length()];
}

int main()
{
    string s, p;
    cin >> s >> p;
    cout << (isMatchRec(s, p) ? "YES" : "NO") << endl;
    cout << (isMatchMem(s, p) ? "YES" : "NO") << endl;
    cout << (isMatchDP(s, p) ? "YES" : "NO") << endl;
    return 0;
}