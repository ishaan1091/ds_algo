#include <iostream>
using namespace std;

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

void sort012(int arr[], int n)
{
    int current = 0, zeroPos = 0, twoPos = n - 1;
    while (current <= twoPos)
    {
        if (arr[current] == 0)
        {
            swap(arr[current++], arr[zeroPos++]);
        }
        else if (arr[current] == 1)
        {
            current++;
        }
        else
        {
            swap(arr[current], arr[twoPos--]);
        }
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
    sort012(arr, n);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    delete[] arr;
    return 0;
}