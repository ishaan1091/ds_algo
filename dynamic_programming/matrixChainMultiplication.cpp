#include <bits/stdc++.h>
using namespace std;

int matrixMultiplication(int n, int arr[])
{
    // code here
    vector<vector<int>> dp(n - 1, vector<int>(n - 1, 0));
    for (int g = 0; g < n - 1; g++)
    {
        for (int i = 0, j = i + g; j < n - 1; i++, j++)
        {
            if (g == 0)
            {
                dp[i][j] = 0;
            }
            else if (g == 1)
            {
                dp[i][j] = arr[i] * arr[i + 1] * arr[i + 2];
            }
            else
            {
                int minOper = INT_MAX;
                for (int k = i; k < j; k++)
                {
                    int oper = dp[i][k] + dp[k + 1][j] + arr[i] * arr[k + 1] * arr[j + 1];
                    minOper = min(minOper, oper);
                }
                dp[i][j] = minOper;
            }
        }
    }
    return dp[0][n - 2];
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int ans = matrixMultiplication(n, arr);
    cout << ans << endl;
    return 0;
}