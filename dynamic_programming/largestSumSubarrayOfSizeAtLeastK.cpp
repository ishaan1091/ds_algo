#include <bits/stdc++.h>
using namespace std;

void kadanesAlgo(long long int arr[], long long int n, vector<long long int> &sumArr)
{
    long long int sum = 0;
    for (long long int i = 0; i < n; i++)
    {
        sum += arr[i];
        sumArr[i] = sum;
        if (sum < 0)
        {
            sum = 0;
        }
    }
}

long long int maxSumWithK(long long int arr[], long long int n, long long int k)
{
    vector<long long int> sumArr(n, 0);
    kadanesAlgo(arr, n, sumArr);
    long long int sum = 0;
    for (int i = 0; i < k; i++)
        sum += arr[i];
    long long int maxSum = sum;
    for (int i = k; i < n; i++)
    {
        sum += arr[i] - arr[i - k];
        maxSum = max(maxSum, max(sum, sum + sumArr[i - k]));
    }
    return maxSum;
}

int main()
{
    long long int n;
    cin >> n;
    long long int arr[n];
    for (long long int i = 0; i < n; i++)
        cin >> arr[i];
    long long int k;
    cin >> k;
    long long int ans = maxSumWithK(arr, n, k);
    cout << ans << endl;
    return 0;
}