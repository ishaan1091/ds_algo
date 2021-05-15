#include <bits/stdc++.h>
using namespace std;

int longestConsecutive(vector<int> &nums)
{
    unordered_map<int, bool> map;
    for (auto i : nums)
    {
        map[i] = true;
    }
    for (auto i : nums)
    {
        if (map.count(i - 1))
            map[i] = false;
    }
    int maxLen = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (map[nums[i]])
        {
            int len = 1;
            while (map.count(nums[i] + len))
            {
                len++;
            }
            if (len > maxLen)
                maxLen = len;
        }
    }
    return maxLen;
}

int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    int ans = longestConsecutive(nums);
    cout << ans << endl;
    return 0;
}