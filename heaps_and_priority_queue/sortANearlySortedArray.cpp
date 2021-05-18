#include <bits/stdc++.h>
using namespace std;

void kSortedArray(vector<int> &arr, int k)
{
    priority_queue<int, vector<int>, greater<int>> pq;
    int i;
    for (i = 0; i < k + 1; i++)
    {
        pq.push(arr[i]);
    }
    int j = 0;
    while (i < arr.size())
    {
        arr[j++] = pq.top();
        pq.pop();
        pq.push(arr[i++]);
    }
    while (!pq.empty())
    {
        arr[j++] = pq.top();
        pq.pop();
    }
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
    kSortedArray(arr, k);
    for (auto i : arr)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}