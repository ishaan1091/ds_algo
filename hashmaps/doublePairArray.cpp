#include <bits/stdc++.h>
using namespace std;

bool canReorderDoubled(vector<int> &nums)
{
    if (nums.size() == 0)
        return true;
    unordered_map<int, int> map;
    sort(nums.begin(), nums.end());
    int i = 0, j = 0;
    while (j < nums.size() && nums[j] < 0)
        j++;
    j--;
    while (i < j)
    {
        int temp = nums[j];
        nums[j] = nums[i];
        nums[i] = temp;
        i++;
        j--;
    }
    for (int k = 0; k < nums.size(); k++)
    {
        if (map.count(nums[k]))
            map[nums[k]]++;
        else
            map[nums[k]] = 1;
    }
    for (int k = 0; k < nums.size(); k++)
    {
        if (map.count(nums[k]))
        {
            if (!map.count(2 * nums[k]))
                return false;
            map[nums[k]]--;
            if (map[nums[k]] == 0)
                map.erase(nums[k]);
            map[2 * nums[k]]--;
            if (map[2 * nums[k]] == 0)
                map.erase(2 * nums[k]);
        }
    }
    return true;
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
    cout << (canReorderDoubled(arr) ? "YES" : "NO") << endl;
    return 0;
}