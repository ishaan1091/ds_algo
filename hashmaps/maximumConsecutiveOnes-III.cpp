#include <bits/stdc++.h>
using namespace std;

// Using release and acquire strategy
int maxConsecutiveOnes1(vector<int> &arr, int k)
{
    unordered_map<int, int> map;
    int ans = 0;
    int i = -1, j = -1;
    while (true)
    {
        bool f1 = false, f2 = false;
        while (i + 1 < arr.size())
        {
            i++;
            f1 = true;
            if (map.count(arr[i]))
            {
                map[arr[i]]++;
            }
            else
            {
                map[arr[i]] = 1;
            }
            if (map.count(0) && map[0] > k)
                break;
            if (i - j > ans)
            {
                ans = i - j;
            }
        }
        while (j < i)
        {
            j++;
            f2 = true;
            map[arr[j]]--;
            if (map[arr[j]] == 0)
                map.erase(arr[j]);
            if ((map.count(0) && map[0] == k) || (k == 0 && !map.count(0)))
                break;
        }
        if (!f1 && !f2)
            break;
    }
    return ans;
}

// Using normal for loop
int maxConsecutiveOnes2(vector<int> &arr, int k)
{
    int ans = 0;
    int j = -1;
    int count = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] == 0)
        {
            count++;
        }
        while (count > k)
        {
            j++;
            if (arr[j] == 0)
            {
                count--;
            }
        }
        int len = i - j;
        if (len > ans)
            ans = len;
    }
    return ans;
}

int main()
{
    vector<int> arr = {1, 1, 0, 1, 0, 0, 1, 1, 0, 1, 0, 1, 1};
    int ans = maxConsecutiveOnes2(arr, 2);
    cout << ans << endl;
    return 0;
}