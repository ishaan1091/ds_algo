#include <bits/stdc++.h>
using namespace std;

int subarraySumEqualsK(vector<int> &arr, int k)
{
    int ans = 0;
    int sum = 0;
    unordered_map<int, int> map;
    map[0] = 1;
    for (auto i : arr)
    {
        sum += i;
        if (map.count(sum))
        {
            map[sum]++;
        }
        else
        {
            map[sum] = 1;
        }
        if (map.count(sum - k))
        {
            ans += map[sum - k];
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
    int k;
    cin >> k;
    int ans = subarraySumEqualsK(arr, k);
    cout << ans << endl;
    return 0;
}