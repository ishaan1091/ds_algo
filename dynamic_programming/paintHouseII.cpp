#include <bits/stdc++.h>
using namespace std;

int paintHouse(vector<vector<int>> &arr)
{
    vector<int> dp(arr[0].size());
    int smallest = INT_MAX, secondSmallest = INT_MAX;
    for (int i = 0; i < arr[0].size(); i++)
    {
        dp[i] = arr[0][i];
        if (dp[i] < smallest)
        {
            secondSmallest = smallest;
            smallest = dp[i];
        }
        else if (dp[i] < secondSmallest)
            secondSmallest = dp[i];
    }
    for (int i = 1; i < arr.size(); i++)
    {
        int newSmallest = INT_MAX, newSecondSmallest = INT_MAX;
        for (int j = 0; j < arr[0].size(); j++)
        {
            if (smallest == dp[j])
                dp[j] = secondSmallest + arr[i][j];
            else
                dp[j] = smallest + arr[i][j];
            if (dp[j] < newSmallest)
            {
                newSecondSmallest = newSmallest;
                newSmallest = dp[j];
            }
            else if (dp[j] < newSecondSmallest)
                newSecondSmallest = dp[j];
        }
        smallest = newSmallest;
        secondSmallest = newSecondSmallest;
    }
    return smallest;
}

int main()
{
    int n, k;
    cin >> n >> k;
    vector<vector<int>> cost(n, vector<int>(k));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < k; j++)
        {
            cin >> cost[i][j];
        }
    }
    int ans = paintHouse(cost);
    cout << ans << endl;
    return 0;
}