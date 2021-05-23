#include <bits/stdc++.h>
using namespace std;

int maxProfit(vector<int> &prices, int fee)
{
    int n = prices.size();
    int boughtState = 0 - prices[0], sellState = 0;
    for (int i = 1; i < n; i++)
    {
        int newBoughtState = max(boughtState, sellState - prices[i]);
        int newSellState = max(boughtState + prices[i] - fee, sellState);
        boughtState = newBoughtState;
        sellState = newSellState;
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
    int fee;
    cin >> fee;
    int ans = maxProfit(prices, fee);
    cout << ans << endl;
    return 0;
}