#include <bits/stdc++.h>
using namespace std;

int maxLen(int arr[], int n)
{
    // Your code here
    unordered_map<int, int> m;
    m[0] = -1;
    int sum = 0;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        if (m.count(sum) > 0)
        {
            int temp = i - m[sum];
            if (temp > ans)
                ans = temp;
        }
        else
        {
            m[sum] = i;
        }
    }
    return ans;
}

int main()
{
    int arr[] = {15, -2, 2, -8, 1, 7, 10, 23};
    cout << maxLen(arr, 8) << endl;
    return 0;
}