#include <bits/stdc++.h>
using namespace std;

// We use count sort when the elements in the array lie in a small/mediocre range rather than being highly spread out
// for example an array with 15 elements but all in range of [3, 9], etc.

void countSort(vector<int> &arr)
{
    int n = arr.size();
    int min_ = INT_MAX, max_ = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        min_ = min(min_, arr[i]);
        max_ = max(max_, arr[i]);
    }
    vector<int> freq(max_ - min_ + 1, 0);
    for (int i = 0; i < n; i++)
    {
        freq[arr[i] - min_]++;
    }
    for (int i = 1; i < freq.size(); i++)
    {
        freq[i] = freq[i] + freq[i - 1];
    }
    vector<int> ans(n, 0);
    for (int i = n - 1; i >= 0; i--)
    {
        int val = arr[i];
        int pos = freq[val - min_];
        freq[val - min_]--;
        ans[pos - 1] = val;
    }
    arr = ans;
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n, 0);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    countSort(arr);
    for (auto i : arr)
        cout << i << " ";
    cout << endl;
    return 0;
}