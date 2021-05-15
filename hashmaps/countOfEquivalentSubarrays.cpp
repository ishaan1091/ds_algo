#include <bits/stdc++.h>
using namespace std;

int countOfEquivalentSubarrays(vector<int> &arr)
{
    int ans = 0;
    unordered_set<int> s;
    for (auto i : arr)
    {
        s.insert(i);
    }
    unordered_map<int, int> map;
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
            if (map.size() == s.size())
            {
                break;
            }
        }
        while (j < i)
        {
            if (map.size() == s.size())
            {
                ans += arr.size() - i;
            }
            j++;
            f2 = true;
            map[arr[j]]--;
            if (map[arr[j]] == 0)
                map.erase(arr[j]);
            if (map.size() < s.size())
                break;
        }
        if (!f1 && !f2)
            break;
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
    int ans = countOfEquivalentSubarrays(arr);
    cout << "SOLUTION: " << ans << endl;
    return 0;
}