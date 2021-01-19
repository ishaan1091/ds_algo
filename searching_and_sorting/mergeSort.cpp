#include <iostream>
using namespace std;

void merge(int arr[], int start, int end)
{
    int mergedArray[end - start + 1];
    int mid = (start + end) / 2;
    int i = start, j = mid + 1, k = 0;
    while (i <= mid && j <= end)
    {
        if (arr[i] <= arr[j])
        {
            mergedArray[k++] = arr[i++];
        }
        else
        {
            mergedArray[k++] = arr[j++];
        }
    }
    while (i <= mid)
    {
        mergedArray[k++] = arr[i++];
    }
    while (j <= end)
    {
        mergedArray[k++] = arr[j++];
    }
    for (int i = 0; i < end - start + 1; i++)
    {
        arr[start + i] = mergedArray[i];
    }
}

void mergeSort(int arr[], int n, int start = 0, int end = -1)
{
    if (end == -1)
    {
        end = n - 1;
    }
    if (start >= end)
    {
        return;
    }
    int mid = (start + end) / 2;
    mergeSort(arr, n, 0, mid);
    mergeSort(arr, n, mid + 1, end);
    merge(arr, start, end);
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
    mergeSort(arr, n);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}
