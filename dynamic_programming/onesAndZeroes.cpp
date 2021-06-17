#include <bits/stdc++.h>
using namespace std;

int findMaxForm(vector<string> &strs, int m, int n)
{
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    int ones, zeros;
    for (auto s : strs)
    {
        ones = zeros = 0;
        for (auto ch : s)
            (ch == '1' ? ones++ : zeros++);
        for (int i = n; i >= ones; i--)
        {
            for (int j = m; j >= zeros; j--)
            {
                dp[i][j] = max(dp[i][j], dp[i - ones][j - zeros] + 1);
            }
        }
    }
    return dp[n][m];
}

int main()
{
    int s;
    cin >> s;
    vector<string> arr(s);
    for (int i = 0; i < s; i++)
        cin >> arr[i];
    int m, n;
    cin >> m >> n;
    int ans = findMaxForm(arr, m, n);
    cout << ans << endl;
    return 0;
}