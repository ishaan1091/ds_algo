#include <iostream>
using namespace std;

int PalinArray(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        int reverseNumber = 0;
        int temp = a[i];
        while (temp != 0)
        {
            reverseNumber *= 10;
            reverseNumber += temp % 10;
            temp /= 10;
        }
        if (reverseNumber != a[i])
        {
            return 0;
        }
    }
    return 1;
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
    int ans = PalinArray(arr, n);
    cout << ans << endl;
    delete[] arr;
    return 0;
}