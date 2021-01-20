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
    for (int i = 1; i <= end; i++)
    {
        if (arr[i] <= arr[start])
        {
            smaller++;
        }
    }
    swap(arr[start], arr[start + smaller]);
    int i = start, j = end;
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

int kthSmallest(int arr[], int start, int end, int k)
{
    int pivotPos = partition(arr, start, end);
    if (pivotPos + 1 == k)
    {
        return arr[pivotPos];
    }
    else if (pivotPos < k)
    {
        return kthSmallest(arr, pivotPos + 1, end, k);
    }
    else
    {
        return kthSmallest(arr, start, pivotPos - 1, k);
    }
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
    int ans = kthSmallest(arr, 0, n - 1, k);
    cout << ans;
    delete[] arr;
    return 0;
}