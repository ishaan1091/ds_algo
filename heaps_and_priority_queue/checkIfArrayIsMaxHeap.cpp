#include <bits/stdc++.h>
using namespace std;

bool isMaxHeap(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        int c1 = (2 * i) + 1;
        int c2 = (2 * i) + 2;
        if ((c1 < n) && (arr[c1] > arr[i]))
            return false;
        if ((c2 < n) && (arr[c2] > arr[i]))
            return false;
    }
    return true;
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << (isMaxHeap(arr, n) ? "YES" : "NO") << endl;
    return 0;
}