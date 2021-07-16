#include <bits/stdc++.h>
using namespace std;

void mergeSortedArrays(vector<int> &arr, int start, int end)
{
    int mid = start + (end - start) / 2;
    int i = start, j = mid + 1;
    vector<int> output(end - start + 1, 0);
    int k = 0;
    while (i <= mid && j <= end)
    {
        if (arr[i] <= arr[j])
            output[k++] = arr[i++];
        else
            output[k++] = arr[j++];
    }
    while (i <= mid)
        output[k++] = arr[i++];
    while (j <= end)
        output[k++] = arr[j++];
    for (int p = start; p <= end; p++)
    {
        arr[p] = output[p - start];
    }
}

void mergeSort(vector<int> &arr, int start = 0, int end = INT_MIN)
{
    if (end == INT_MIN)
        end = arr.size() - 1;
    if (start >= end)
        return;
    int mid = start + (end - start) / 2;
    mergeSort(arr, start, mid);
    mergeSort(arr, mid + 1, end);
    mergeSortedArrays(arr, start, end);
}

int nextGap(int gap)
{
    if (gap <= 1)
        return 0;
    return (gap / 2) + (gap % 2);
}

void mergeSortedArraysConstantSpace(vector<int> &arr, int start, int end)
{
    for (int gap = nextGap(end - start + 1); gap >= 1; gap = nextGap(gap))
    {
        int i = start, j = start + gap;
        for (; j <= end; i++, j++)
        {
            if (arr[i] > arr[j])
                swap(arr[i], arr[j]);
        }
    }
}

void mergeSortConstantSpace(vector<int> &arr, int start = 0, int end = INT_MIN)
{
    if (end == INT_MIN)
        end = arr.size() - 1;
    if (start >= end)
        return;
    int mid = start + (end - start) / 2;
    mergeSort(arr, start, mid);
    mergeSort(arr, mid + 1, end);
    mergeSortedArraysConstantSpace(arr, start, end);
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    vector<int> tempArr = arr;
    cout << "Merge Sort : ";
    mergeSort(arr);
    for (auto i : arr)
        cout << i << " ";
    cout << endl;
    arr = tempArr;
    cout << "Merge Sort Using Constant Space : ";
    mergeSortConstantSpace(arr);
    for (auto i : arr)
        cout << i << " ";
    cout << endl;
    return 0;
}
