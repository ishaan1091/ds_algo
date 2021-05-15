#include <bits/stdc++.h>
using namespace std;

int longestSubarrayDivisibleByK(vector<int> &nums, int k)
{
    int ans = 0;
    int sum = 0;
    unordered_map<int, int> map;
    map[0] = 1;
    for (int i = 0; i < nums.size(); i++)
    {
        sum += nums[i];
        int r = sum % k;
        if (r < 0)
            r += k;
        if (map.count(r))
        {
            ans += map[r];
            map[r]++;
        }
        else
        {
            map[r] = 1;
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
    int k;
    cin >> k;
    int ans = longestSubarrayDivisibleByK(nums, k);
    cout << ans << endl;
    return 0;
}