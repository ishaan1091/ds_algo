#include <bits/stdc++.h>
using namespace std;

int countSubstrings(string s)
{
    vector<vector<bool>> dp(s.length(), vector<bool>(s.length(), 0));
    int count = 0;
    for (int g = 0; g < s.length(); g++)
    {
        for (int i = 0, j = g; true; i++, j++)
        {
            if (j == s.length())
                break;
            if (g == 0)
            {
                dp[i][j] = true;
                count++;
            }
            else if (g == 1)
            {
                dp[i][j] = s[i] == s[j];
                if (dp[i][j])
                    count++;
            }
            else
            {
                dp[i][j] = s[i] == s[j] && dp[i + 1][j - 1];
                if (dp[i][j])
                    count++;
            }
        }
    }
    return count;
}

int main()
{
    string s;
    cin >> s;
    int ans = countSubstrings(s);
    cout << ans << endl;
    return 0;
}