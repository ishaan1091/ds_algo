#include <bits/stdc++.h>
using namespace std;

void countSort(vector<int> &arr, int exp)
{
    int n = arr.size();
    vector<int> freq(10, 0);
    for (int i = 0; i < n; i++)
    {
        freq[(arr[i] / exp) % 10]++;
    }
    for (int i = 1; i < freq.size(); i++)
    {
        freq[i] = freq[i] + freq[i - 1];
    }
    vector<int> ans(n, 0);
    for (int i = n - 1; i >= 0; i--)
    {
        int val = arr[i];
        int pos = freq[(arr[i] / exp) % 10];
        freq[(arr[i] / exp) % 10]--;
        ans[pos - 1] = val;
    }
    arr = ans;
}

void radixSort(vector<int> &arr)
{
    int max_ = INT_MIN;
    for (auto i : arr)
        max_ = max(max_, i);
    int exp = 1;
    while (exp <= max_)
    {
        countSort(arr, exp);
        exp *= 10;
    }
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n, 0);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    radixSort(arr);
    for (auto i : arr)
        cout << i << " ";
    cout << endl;
    return 0;
}