#include <bits/stdc++.h>
using namespace std;

void rotate(vector<int> &arr, int start, int end)
{
    int temp = arr[end];
    for (int i = end; i > start; i--)
    {
        arr[i] = arr[i - 1];
    }
    arr[start] = temp;
}

void rearrange(vector<int> &arr)
{
    int i = 0, idx = -1;
    while (i < arr.size())
    {
        if (idx == -1)
        {
            if (i % 2 == 0 && arr[i] >= 0)
                idx = i;
            else if (i % 2 != 0 && arr[i] < 0)
                idx = i;
        }
        else
        {
            bool posRequired = (idx % 2 != 0);
            if (arr[i] >= 0 && posRequired)
            {
                rotate(arr, idx, i);
                i = idx;
                idx = -1;
            }
            else if (arr[i] < 0 && !posRequired)
            {
                rotate(arr, idx, i);
                i = idx;
                idx = -1;
            }
        }
        i++;
    }
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    rearrange(arr);
    for (auto i : arr)
        cout << i << " ";
    cout << endl;
    return 0;
}