#include <bits/stdc++.h>
using namespace std;

int SumOfMSIS(vector<int> &arr)
{
    int n = arr.size();
    vector<int> dp(n, 0);
    for (int i = 0; i < n; i++)
    {
        int maxSum = 0;
        for (int j = 0; j < i; j++)
        {
            if (arr[j] < arr[i])
                maxSum = max(maxSum, dp[j]);
        }
        dp[i] = maxSum + arr[i];
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans = max(ans, dp[i]);
    }
    return ans;
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int ans = SumOfMSIS(arr);
    cout << ans << endl;
    return 0;
}