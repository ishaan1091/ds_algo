#include <iostream>
#include <vector>
using namespace std;
#define ARR_MAX 3000

int multiply(int arr[], int n, int num)
{
    int carry = 0;
    for (int i = ARR_MAX - 1; i >= ARR_MAX - n; i--)
    {
        arr[i] *= num;
        arr[i] += carry;
        carry = arr[i] / 10;
        arr[i] = arr[i] % 10;
    }
    while (carry)
    {
        arr[ARR_MAX - n - 1] = carry % 10;
        carry /= 10;
        n++;
    }
    return n;
}

int factorial(int arr[], int num)
{
    if (num == 1 || num == 0)
    {
        arr[ARR_MAX - 1] = 1;
        return 1;
    }
    int n = factorial(arr, num - 1);
    n = multiply(arr, n, num);
    return n;
}

int main()
{
    //code
    int t;
    cin >> t;
    int arr[ARR_MAX];
    for (int x = 0; x < t; x++)
    {
        int num;
        cin >> num;
        int n = factorial(arr, num);
        for (int i = ARR_MAX - n; i < ARR_MAX; i++)
        {
            cout << arr[i];
        }
        cout << endl;
    }
    return 0;
}