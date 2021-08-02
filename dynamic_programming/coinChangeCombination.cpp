#include <bits/stdc++.h>
using namespace std;

int coinChangeCombination(vector<int> &arr, int amount)
{
    if (amount == 0)
        return 0;
    int n = arr.size();
    vector<int> dp(amount + 1, 0);
    dp[0] = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = arr[i]; j < amount + 1; j++)
        {
            dp[j] += dp[j - arr[i]];
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
    int ans = coinChangeCombination(arr, amount);
    cout << ans << endl;
    return 0;
}