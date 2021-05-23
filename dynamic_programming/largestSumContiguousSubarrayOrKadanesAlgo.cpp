#include <bits/stdc++.h>
using namespace std;

int maxSubarraySum(int arr[], int n)
{
    // Your code here
    int sum = 0, maxSum = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        maxSum = max(sum, maxSum);
        if (sum < 0)
            sum = 0;
    }
    return maxSum;
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int ans = maxSubarraySum(arr, n);
    cout << ans << endl;
    return 0;
}