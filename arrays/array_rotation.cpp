#include <iostream>
using namespace std;

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

void reverse(int arr[], int start, int end)
{
    int i = start, j = end;
    while (i < j)
    {
        swap(arr[i++], arr[j--]);
    }
}

void reversalRotate(int arr[], int n, int d)
{
    d = d % n;
    reverse(arr, 0, n - 1);
    reverse(arr, 0, n - d - 1);
    reverse(arr, n - d, n - 1);
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
    int d;
    cin >> d;
    reversalRotate(arr, n, d);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    delete[] arr;
    return 0;
}