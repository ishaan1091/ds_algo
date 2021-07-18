#include <bits/stdc++.h>
using namespace std;

int partition(vector<int> &arr, int start, int end)
{
    // random partitioning
    srand(time(NULL));
    int random = start + rand() % (end - start);
    swap(arr[random], arr[start]);
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

void quickSort(vector<int> &arr, int start = 0, int end = INT_MIN)
{
    if (end == INT_MIN)
        end = arr.size() - 1;
    if (start >= end)
        return;
    int pivot = partition(arr, start, end);
    quickSort(arr, start, pivot - 1);
    quickSort(arr, pivot + 1, end);
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    quickSort(arr);
    for (auto i : arr)
        cout << i << " ";
    cout << endl;
    return 0;
}
