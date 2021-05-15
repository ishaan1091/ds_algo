#include <bits/stdc++.h>
using namespace std;

int fourSumCount(vector<int> &nums1, vector<int> &nums2, vector<int> &nums3, vector<int> &nums4)
{
    unordered_map<int, int> map;
    int count = 0;
    for (auto i : nums1)
    {
        for (auto j : nums2)
        {
            map[i + j]++;
        }
    }
    for (auto i : nums3)
    {
        for (auto j : nums4)
        {
            if (map.count(0 - i - j))
                count += map[0 - i - j];
        }
    }
    return count;
}

int main()
{
    int n;
    cin >> n;
    vector<int> nums1(n);
    vector<int> nums2(n);
    vector<int> nums3(n);
    vector<int> nums4(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums1[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> nums2[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> nums3[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> nums4[i];
    }
    int ans = fourSumCount(nums1, nums2, nums3, nums4);
    cout << ans << endl;
    return 0;
}