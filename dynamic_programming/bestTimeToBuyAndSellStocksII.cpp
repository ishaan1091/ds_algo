#include <bits/stdc++.h>
using namespace std;

int maxProfit(vector<int> &arr)
{
    int n = arr.size();
    int min = arr[0], profit = 0, totalProfit = 0;
    for (int i = 1; i < n; i++)
    {
        if (arr[i] < arr[i - 1])
        {
            totalProfit += profit;
            profit = 0;
            min = arr[i];
        }
        if (arr[i] < min)
            min = arr[i];
        else if (arr[i] - min > profit)
            profit = arr[i] - min;
    }
    totalProfit += profit;
    return totalProfit;
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