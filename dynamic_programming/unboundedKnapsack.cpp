#include <bits/stdc++.h>
using namespace std;

int unboundedKnapsack(vector<int> &val, vector<int> &weights, int capacity)
{
    int n = weights.size();
    int dp[capacity + 1];
    memset(dp, 0, sizeof(dp));
    dp[0] = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = weights[i]; j <= capacity; j++)
        {
            if (val[i] + dp[j - weights[i]] > dp[j])
            {
                dp[j] = val[i] + dp[j - weights[i]];
            }
        }
    }
    return dp[capacity];
}

int main()
{
    int n;
    cin >> n;
    vector<int> val(n);
    vector<int> weights(n);
    for (int i = 0; i < n; i++)
    {
        cin >> val[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> weights[i];
    }
    int capacity;
    cin >> capacity;
    int ans = unboundedKnapsack(val, weights, capacity);
    cout << ans << endl;
    return 0;
}