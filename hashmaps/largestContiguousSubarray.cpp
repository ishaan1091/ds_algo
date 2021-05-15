#include <bits/stdc++.h>
using namespace std;

int largestContiguousSubarray(vector<int> &arr)
{
    int ans = 0;
    for (int i = 0; i < arr.size() - 1; i++)
    {
        int maxVal = arr[i];
        int minVal = arr[i];
        unordered_set<int> set;
        set.insert(arr[i]);
        for (int j = i + 1; j < arr.size(); j++)
        {
            if (set.count(arr[j]))
                break;
            set.insert(arr[j]);
            minVal = min(arr[j], minVal);
            maxVal = max(arr[j], maxVal);
            if (maxVal - minVal == j - i)
            {
                int len = j - i + 1;
                if (len > ans)
                {
                    ans = len;
                }
            }
        }
    }
    return ans;
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
    int ans = largestContiguousSubarray(arr);
    cout << "SOLUTION: " << ans << endl;
    return 0;
}