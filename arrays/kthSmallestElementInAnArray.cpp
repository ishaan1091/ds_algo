#include <bits/stdc++.h>
using namespace std;

int partition(int arr[], int start, int end)
{
    int pivot = arr[start], i = start, j = start;
    while (j <= end)
    {
        if (arr[j] <= pivot)
        {
            swap(arr[i], arr[j]);
            i++;
        }
        j++;
    }
    swap(arr[start], arr[i - 1]);
    return i - 1;
}

int quickSelect(int arr[], int start, int end, int k)
{
    int pivot = partition(arr, start, end);
    if (pivot == k - 1)
        return arr[k - 1];
    else if (pivot < k - 1)
        return quickSelect(arr, pivot + 1, end, k);
    else
        return quickSelect(arr, start, pivot - 1, k);
    return -1;
}

int main()
{
    int n;
    cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int k;
    cin >> k;
    int ans = quickSelect(arr, 0, n - 1, n - k + 1);
    cout << ans << endl;
    delete[] arr;
    return 0;
}