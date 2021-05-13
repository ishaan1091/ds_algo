#include <bits/stdc++.h>
using namespace std;

int longestSubarray(vector<int> &nums)
{
    int count0 = 0, count1 = 0, count2 = 0;
    int ans = 0;
    unordered_map<string, int> map;
    map["0 0"] = -1;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] == 0)
            count0++;
        else if (nums[i] == 1)
            count1++;
        else
            count2++;
        string str = to_string(count1 - count0) + " " + to_string(count2 - count1);
        if (map.count(str))
        {
            int len = i - map[str];
            if (len > ans)
                ans = len;
        }
        else
        {
            map[str] = i;
        }
    }
    return ans;
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
    int ans = longestSubarray(nums);
    cout << ans << endl;
    return 0;
}