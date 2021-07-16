#include <bits/stdc++.h>
using namespace std;

void shellSort(vector<int> &arr)
{
    int n = arr.size();
    for (int gap = n / 2; gap >= 1; gap /= 2)
    {
        for (int i = gap; i < n; i++)
        {
            int temp = arr[i], j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
                arr[j] = arr[j - gap];
            arr[j] = temp;
        }
    }
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    shellSort(arr);
    cout << "Sorting using Shell Sort : ";
    for (auto i : arr)
        cout << i << ' ';
    cout << endl;
    return 0;
}