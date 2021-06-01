#include <bits/stdc++.h>
using namespace std;

// O(N^2) solution
int lengthOfLIS1(vector<int> &arr)
{
    int n = arr.size();
    vector<int> dp(n, 0);
    for (int i = 0; i < n; i++)
    {
        int maxLength = 0;
        for (int j = 0; j < i; j++)
        {
            if (arr[j] < arr[i])
                maxLength = max(maxLength, dp[j]);
        }
        dp[i] = maxLength + 1;
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans = max(ans, dp[i]);
    }
    return ans;
}

// O(NlogN) using binary search
int findIndex(vector<int> arr, int start, int end, int num)
{
    while (start < end)
    {
        int mid = (start + end) / 2;
        if (arr[mid] < num)
        {
            start = mid + 1;
        }
        else if (arr[mid] > num)
        {
            end = mid;
        }
        else
        {
            return mid;
        }
    }
    return end;
}

int lengthOfLIS2(vector<int> &arr)
{
    int n = arr.size();
    vector<int> dp(n, 0);
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (count == 0 || arr[i] > dp[count - 1])
        {
            dp[count++] = arr[i];
        }
        else
        {
            // int replaceIndex = lower_bound(dp.begin(), dp.begin()+count, arr[i])-dp.begin();
            int replaceIndex = findIndex(dp, 0, count - 1, arr[i]);
            dp[replaceIndex] = arr[i];
        }
    }
    return count;
}

// O(NlogN) solution using C++ STL binary search function (lower_bound)
int lengthOfLIS3(vector<int> &arr)
{
    int n = arr.size();
    vector<int> dp(n, 0);
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (count == 0 || arr[i] > dp[count - 1])
        {
            dp[count++] = arr[i];
        }
        else
        {
            int replaceIndex = lower_bound(dp.begin(), dp.begin() + count, arr[i]) - dp.begin();
            dp[replaceIndex] = arr[i];
        }
    }
    return count;
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int ans = lengthOfLIS1(arr);
    cout << "Using Method 1 : " << ans << endl;
    ans = lengthOfLIS2(arr);
    cout << "Using Method 2 : " << ans << endl;
    ans = lengthOfLIS3(arr);
    cout << "Using Method 3 : " << ans << endl;
    return 0;
}