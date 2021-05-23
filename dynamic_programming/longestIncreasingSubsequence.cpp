#include <bits/stdc++.h>
using namespace std;

int lengthOfLIS(vector<int> &arr)
{
    int n = arr.size();
    vector<int> dp(n, 0);
    for (int i = 0; i < n; i++)
    {
        int maxLength = 0;
        for (int j = 0; j < i; j++)
        {
            if (arr[j] < arr[i])
                maxLength = max(maxLength, dp[j]);
        }
        dp[i] = maxLength + 1;
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
    int ans = lengthOfLIS(arr);
    cout << ans << endl;
    return 0;
}