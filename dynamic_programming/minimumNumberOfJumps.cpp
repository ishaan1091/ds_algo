#include <bits/stdc++.h>
using namespace std;

int minJumps(int arr[], int n)
{
    vector<int> dp(n, INT_MAX);
    dp[n - 1] = 0;
    for (int i = n - 2; i >= 0; i--)
    {
        for (int j = 1; j <= arr[i] && i + j < n; j++)
        {
            dp[i] = min(dp[i], dp[i + j]);
        }
        if (dp[i] != INT_MAX)
            dp[i]++;
    }
    if (dp[0] == INT_MAX)
        return -1;
    return dp[0];
}

int main()
{
    int n;
    cin >> n;
    int *jumps = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> jumps[i];
    }
    int ans = minJumps(jumps, n);
    cout << ans << endl;
    delete[] jumps;
    return 0;
}