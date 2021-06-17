#include <bits/stdc++.h>
using namespace std;

// Cut method
int cutRod1(int price[], int n)
{
    vector<int> dp(n, 0);
    dp[0] = price[0];
    for (int i = 1; i < n; i++)
    {
        int max = price[i];
        for (int j = i - 1; j >= 0; j--)
        {
            int revenue = price[i - j - 1] + dp[j];
            if (revenue > max)
                max = revenue;
        }
        dp[i] = max;
    }
    return dp[n - 1];
}

// Left-Right method
int cutRod2(int price[], int n)
{
    vector<int> dp(n, 0);
    dp[0] = price[0];
    for (int i = 1; i < n; i++)
    {
        int max = price[i];
        int l = 0, r = i - 1;
        while (l <= r)
        {
            if (max < dp[l] + dp[r])
                max = dp[l] + dp[r];
            l++;
            r--;
        }
        dp[i] = max;
    }
    return dp[n - 1];
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int ans = cutRod1(arr, n);
    cout << ans << endl;
    ans = cutRod2(arr, n);
    cout << ans << endl;
    return 0;
}