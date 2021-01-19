#include <iostream>
#include <bits/stdc++.h>
#include <cstring>
using namespace std;

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int t;
    cin >> t;
    for (int x = 0; x < t; x++)
    {
        int n, i;
        cin >> n;
        int *arr = new int[n];
        for (i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        rotate(arr, n);
        printArray(arr, n);
        delete[] arr;
    }
    return 0;
}
