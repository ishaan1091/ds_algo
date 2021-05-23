#include <bits/stdc++.h>
using namespace std;

int longestBS(vector<int> &arr)
{
    int n = arr.size();
    vector<int> dpIncreasing(n, 0);
    vector<int> dpDecreasing(n, 0);
    for (int i = 0; i < n; i++)
    {
        int maxLengthIncreasing = 0;
        int maxLengthDecreasing = 0;
        for (int j = 0; j < i; j++)
        {
            if (arr[j] < arr[i])
                maxLengthIncreasing = max(maxLengthIncreasing, dpIncreasing[j]);
            if (arr[n - j - 1] < arr[n - i - 1])
                maxLengthDecreasing = max(maxLengthDecreasing, dpDecreasing[n - j - 1]);
        }
        dpIncreasing[i] = maxLengthIncreasing + 1;
        dpDecreasing[n - i - 1] = maxLengthDecreasing + 1;
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans = max(ans, dpIncreasing[i] + dpDecreasing[i]);
    }
    return ans - 1;
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int ans = longestBS(arr);
    cout << ans << endl;
    return 0;
}