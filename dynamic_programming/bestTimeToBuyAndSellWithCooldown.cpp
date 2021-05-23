#include <bits/stdc++.h>
using namespace std;

int maxProfit(vector<int> &prices)
{
    int n = prices.size();
    int boughtState = 0 - prices[0], sellState = 0, cooldownState = 0;
    for (int i = 1; i < n; i++)
    {
        int newBoughtState = max(boughtState, cooldownState - prices[i]);
        int newSellState = max(boughtState + prices[i], sellState);
        int newCooldownState = max(cooldownState, sellState);
        boughtState = newBoughtState;
        sellState = newSellState;
        cooldownState = newCooldownState;
    }
    return sellState;
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