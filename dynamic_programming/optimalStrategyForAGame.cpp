#include <bits/stdc++.h>
using namespace std;

long long maximumAmount(int arr[], int n)
{
    // Your code here
    vector<vector<int>> dp(n, vector<int>(n, 0));
    for (int g = 0; g < n; g++)
    {
        for (int i = 0, j = g; j < n; i++, j++)
        {
            if (g == 0)
                dp[i][j] = arr[i];
            else if (g == 1)
                dp[i][j] = max(arr[i], arr[j]);
            else
            {
                dp[i][j] = max(arr[i] + min(dp[i + 2][j], dp[i + 1][j - 1]), arr[j] + min(dp[i][j - 2], dp[i + 1][j - 1]));
            }
        }
    }
    return dp[0][n - 1];
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    long long ans = maximumAmount(arr, n);
    cout << ans << endl;
    return 0;
}