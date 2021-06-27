#include <iostream>
using namespace std;

int kadanesAlgo(int arr[], int n)
{
    int sum = 0, maxSum = arr[0];
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        if (sum > maxSum)
        {
            maxSum = sum;
        }
        if (sum < 0)
        {
            sum = 0;
        }
    }
    return maxSum;
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
    int ans = kadanesAlgo(arr, n);
    cout << ans << endl;
    delete[] arr;
    return 0;
}