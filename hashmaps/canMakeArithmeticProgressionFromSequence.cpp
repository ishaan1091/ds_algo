#include <bits/stdc++.h>
using namespace std;

bool canMakeArithmeticProgression(vector<int> &arr)
{
    unordered_map<int, int> map;
    int min = INT_MAX, max = INT_MIN;
    for (auto i : arr)
    {
        if (map.count(i))
            map[i]++;
        else
            map[i] = 1;
        if (i < min)
            min = i;
        if (i > max)
            max = i;
    }
    if (map.size() <= 1)
        return true;
    int d = (max - min) / (map.size() - 1);
    int sum = min;
    for (int i = 0; i < map.size(); i++, sum += d)
    {
        if (!map.count(sum) || map[sum] > 1)
            return false;
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
    cout << (canMakeArithmeticProgression(arr) ? "YES" : "NO") << endl;
    return 0;
}