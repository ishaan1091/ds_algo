#include <bits/stdc++.h>
using namespace std;

int numRabbits(vector<int> &answers)
{
    int ans = 0;
    unordered_map<int, int> map;
    for (auto i : answers)
    {
        if (map.count(i))
            map[i]++;
        else
            map[i] = 1;
    }
    for (auto it : map)
    {
        int temp = ceil((double)it.second / ((double)it.first + 1));
        ans += (temp * (it.first + 1));
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
    int ans = numRabbits(arr);
    cout << ans << endl;
    return 0;
}