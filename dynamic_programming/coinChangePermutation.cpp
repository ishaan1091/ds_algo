#include <bits/stdc++.h>
using namespace std;

int coinChangePermutation(vector<int> &arr, int amount)
{
    if (amount == 0)
        return 0;
    int n = arr.size();
    vector<int> dp(amount + 1, 0);
    dp[0] = 1;
    for (int i = 1; i < amount + 1; i++)
    {
        for (auto j : arr)
        {
            if (i - j >= 0)
            {
                dp[i] += dp[i - j];
            }
        }
    }
    return dp[amount];
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int amount;
    cin >> amount;
    int ans = coinChangePermutation(arr, amount);
    cout << ans << endl;
    return 0;
}