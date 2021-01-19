#include <iostream>
using namespace std;

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

int partition(int arr[], int start, int end)
{
    int smaller = 0;
    for (int i = start + 1; i <= end; i++)
    {
        if (arr[i] < arr[start])
        {
            smaller++;
        }
    }
    int i = start, j = end;
    swap(arr[start], arr[start + smaller]);
    while (i < start + smaller && j > start + smaller)
    {
        while (arr[i] <= arr[start + smaller] && i < start + smaller)
        {
            i++;
        }
        while (arr[j] > arr[start + smaller] && j > start + smaller)
        {
            j--;
        }
        if (i < j)
        {
            swap(arr[i], arr[j]);
        }
    }
    return start + smaller;
}

void quickSort(int arr[], int n, int start = 0, int end = -1)
{
    if (end == -1)
    {
        end = n - 1;
    }
    if (start >= end)
    {
        return;
    }
    int pivotPos = partition(arr, start, end);
    quickSort(arr, n, start, pivotPos - 1);
    quickSort(arr, n, pivotPos + 1, end);
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
    quickSort(arr, n);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}