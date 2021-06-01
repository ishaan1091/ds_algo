#include <bits/stdc++.h>
using namespace std;

// O(N^2) solution
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

// O(NlogN) solution
int longestBSOptimised(vector<int> &arr)
{
    int n = arr.size();
    vector<int> dpIncreasing(n, 0);
    vector<int> lenIncreasing(n, 0);
    int countIncreasing = 0;
    vector<int> dpDecreasing(n, 0);
    vector<int> lenDecreasing(n, 0);
    int countDecreasing = 0;
    for (int i = 0; i < n; i++)
    {
        if (countIncreasing == 0 || dpIncreasing[countIncreasing - 1] < arr[i])
        {
            dpIncreasing[countIncreasing++] = arr[i];
            lenIncreasing[i] = countIncreasing;
        }
        else
        {
            int replaceIndexIncreasing = lower_bound(dpIncreasing.begin(), dpIncreasing.begin() + countIncreasing, arr[i]) - dpIncreasing.begin();
            dpIncreasing[replaceIndexIncreasing] = arr[i];
            lenIncreasing[i] = replaceIndexIncreasing + 1;
        }
        if (countDecreasing == 0 || dpDecreasing[countDecreasing - 1] < arr[n - i - 1])
        {
            dpDecreasing[countDecreasing++] = arr[n - i - 1];
            lenDecreasing[n - i - 1] = countDecreasing;
        }
        else
        {
            int replaceIndexDecreasing = lower_bound(dpDecreasing.begin(), dpDecreasing.begin() + countDecreasing, arr[n - i - 1]) - dpDecreasing.begin();
            dpDecreasing[replaceIndexDecreasing] = arr[n - i - 1];
            lenDecreasing[n - i - 1] = replaceIndexDecreasing + 1;
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans = max(lenDecreasing[i] + lenIncreasing[i] - 1, ans);
    }
    return ans;
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
    ans = longestBSOptimised(arr);
    cout << ans << endl;
    return 0;
}