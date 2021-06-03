#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007

int distinctSubseqII(string s)
{
    vector<long> dp(s.length() + 1, 0);
    dp[0] = 1;
    unordered_map<char, int> lastOccurence;
    for (int i = 1; i <= s.length(); i++)
    {
        dp[i] = (2 * dp[i - 1]) % mod;
        if (lastOccurence.count(s[i - 1]))
        {
            dp[i] -= dp[lastOccurence[s[i - 1]] - 1];
            if (dp[i] < 0)
                dp[i] += mod;
        }
        lastOccurence[s[i - 1]] = i;
    }
    return dp[s.length()] - 1;
}

int main()
{
    string s;
    cin >> s;
    int ans = distinctSubseqII(s);
    cout << ans << endl;
    return 0;
}