#include <bits/stdc++.h>
using namespace std;

int minSubarraySum(vector<int> &arr)
{
    int n = arr.size();
    int minSum = INT_MAX, sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        minSum = min(sum, minSum);
        if (sum > 0)
            sum = 0;
    }
    return minSum;
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
    int ans = minSubarraySum(arr);
    cout << ans << endl;
    return 0;
}