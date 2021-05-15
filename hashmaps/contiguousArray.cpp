#include <bits/stdc++.h>
using namespace std;

int findMaxLength(vector<int> &nums)
{
    int ans = 0;
    int sum = 0;
    unordered_map<int, int> map;
    map[0] = -1;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] == 0)
            sum--;
        else
            sum++;
        if (map.count(sum))
        {
            int len = i - map[sum];
            if (len > ans)
                ans = len;
        }
        else
        {
            map[sum] = i;
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
    int ans = findMaxLength(nums);
    cout << ans << endl;
    return 0;
}