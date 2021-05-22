#include <bits/stdc++.h>
using namespace std;

int FindMaxSum(int arr[], int n)
{
    // Your code here
    int include = arr[0];
    int exclude = 0;
    for (int i = 1; i < n; i++)
    {
        int newInclude = exclude + arr[i];
        int newExclude = max(exclude, include);
        include = newInclude;
        exclude = newExclude;
    }
    return max(include, exclude);
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int ans = FindMaxSum(arr, n);
    cout << ans << endl;
    return 0;
}