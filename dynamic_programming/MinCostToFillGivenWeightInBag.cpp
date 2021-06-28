#include <bits/stdc++.h>
using namespace std;

int minimumCost(int cost[], int n, int w)
{
    // Your code goes here
    vector<int> dp(w + 1, 0);
    for (int i = 1; i <= w; i++)
    {
        int minCost = INT_MAX;
        for (int j = 0; j < i && j < n; j++)
        {
            if (cost[j] == -1 || dp[i - j - 1] == -1)
                continue;
            minCost = min(minCost, dp[i - j - 1] + cost[j]);
        }
        dp[i] = minCost == INT_MAX ? -1 : minCost;
    }
    return dp[w];
}

int main()
{
    int n, w;
    cin >> n >> w;
    int cost[n];
    for (int i = 0; i < n; i++)
        cin >> cost[i];
    int ans = minimumCost(cost, n, w);
    cout << ans << endl;
    return 0;
}