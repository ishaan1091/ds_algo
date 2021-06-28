#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007

int kadanesAlgo(vector<int> &arr, int kConcat)
{
    int n = arr.size();
    int sum = 0, maxSum = 0;
    for (int i = 0, k = 0; k < kConcat; i = (i + 1) % n)
    {
        sum += arr[i];
        if (sum > maxSum)
        {
            maxSum = sum % mod;
        }
        if (sum < 0)
        {
            sum = 0;
        }
        sum %= mod;
        k += (i + 1) / n;
    }
    return maxSum;
}

int kConcatenationMaxSum(vector<int> &arr, int k)
{
    long long int sum = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        sum += arr[i];
    }
    if (k == 1)
    {
        return kadanesAlgo(arr, 1);
    }
    else if (sum <= 0)
    {
        return kadanesAlgo(arr, 2);
    }
    else
    {
        return (kadanesAlgo(arr, 2) + (k - 2) * sum) % mod;
    }
}

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int ans = kConcatenationMaxSum(arr, k);
    cout << ans << endl;
    return 0;
}