#include <bits/stdc++.h>
using namespace std;

int minScoreTriangulation(vector<int> &values)
{
    int n = values.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));
    for (int g = 0; g < n; g++)
    {
        for (int i = 0, j = i + g; j < n; i++, j++)
        {
            if (g == 0 || g == 1)
                dp[i][j] = 0;
            else if (g == 2)
                dp[i][j] = values[i] * values[i + 1] * values[i + 2];
            else
            {
                int finalAns = INT_MAX;
                for (int k = 0; k < g - 1; k++)
                {
                    int ans = values[i] * values[i + k + 1] * values[j];
                    ans += dp[i + k + 1][j];
                    ans += dp[i][j - g + 1 + k];
                    finalAns = min(finalAns, ans);
                }
                dp[i][j] = finalAns;
            }
        }
    }
    return dp[0][n - 1];
}

int main()
{
    int n;
    cin >> n;
    vector<int> values(n);
    for (int i = 0; i < n; i++)
        cin >> values[i];
    int ans = minScoreTriangulation(values);
    cout << ans << endl;
    return 0;
}