#include <bits/stdc++.h>
using namespace std;

bool canArrange(vector<int> &arr, int k)
{
    unordered_map<int, int> m;
    for (auto i : arr)
    {
        int r = i % k;
        if (r < 0)
            r += k;
        if (m.count(r) > 0)
        {
            m[r]++;
        }
        else
        {
            m[r] = 1;
        }
    }
    for (auto i : m)
    {
        int remainder = i.first;
        int times = i.second;
        if (remainder == 0)
        {
            if (times % 2 != 0)
            {
                return false;
            }
        }
        else if (k % 2 == 0 && remainder == k / 2)
        {
            if (times % 2 != 0)
            {
                return false;
            }
        }
        else
        {
            int otherRemainder = (m.count(k - remainder) ? m[k - remainder] : 0);
            if (times != otherRemainder)
            {
                return false;
            }
        }
    }
    return true;
}

int main()
{
    vector<int> arr = {-4, -7, 5, 2, 9, 1, 10, 4, -8, -3};
    cout << (canArrange(arr, 3) ? "YES" : "NO") << endl;
    return 0;
}