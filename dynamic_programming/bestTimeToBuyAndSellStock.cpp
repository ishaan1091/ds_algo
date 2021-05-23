#include <bits/stdc++.h>
using namespace std;

int maxProfit(vector<int> &prices)
{
    int n = prices.size();
    int min = prices[0], profit = 0;
    for (int i = 1; i < n; i++)
    {
        if (prices[i] - min > profit)
            profit = prices[i] - min;
        if (prices[i] < min)
            min = prices[i];
    }
    return profit;
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int ans = maxProfit(arr);
    cout << ans << endl;
    return 0;
}