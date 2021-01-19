#include <iostream>
using namespace std;

int maxProfit(int arr[], int n)
{
    int i = 0, j = 1, min = INT_MAX, profit = 0;
    for (; i < n - 1; i++, j++)
    {
        if (arr[i] < min)
        {
            min = arr[i];
        }
        if (arr[j] - min > profit)
        {
            profit = arr[j] - min;
        }
    }
    return profit;
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
    int profit = maxProfit(arr, n);
    cout << profit << endl;
    delete[] arr;
    return 0;
}