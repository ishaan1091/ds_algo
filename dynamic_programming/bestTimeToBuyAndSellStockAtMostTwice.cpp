#include <bits/stdc++.h>
using namespace std;

int maxProfit(vector<int> &prices)
{
    int n = prices.size();
    int min = INT_MAX, max = INT_MIN;
    int maxProfitForward = 0, maxProfitBackward = 0;
    vector<int> dpForward(n, 0);
    vector<int> dpBackward(n, 0);
    for (int i = 0, j = n - 1; i < n; i++, j--)
    {
        if (prices[i] < min)
            min = prices[i];
        if (prices[j] > max)
            max = prices[j];
        int profitForward = prices[i] - min;
        int profitBackward = max - prices[j];
        if (profitForward > maxProfitForward)
            maxProfitForward = profitForward;
        if (profitBackward > maxProfitBackward)
            maxProfitBackward = profitBackward;
        dpForward[i] = maxProfitForward;
        dpBackward[j] = maxProfitBackward;
    }
    int maxProfit = 0;
    for (int i = 0; i < n; i++)
    {
        if (maxProfit < dpForward[i] + dpBackward[i])
            maxProfit = dpForward[i] + dpBackward[i];
    }
    return maxProfit;
}

int main()
{
    int n;
    cin >> n;
    vector<int> prices(n);
    for (int i = 0; i < n; i++)
    {
        cin >> prices[i];
    }
    int ans = maxProfit(prices);
    cout << ans << endl;
    return 0;
}