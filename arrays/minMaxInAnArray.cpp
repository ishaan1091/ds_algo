#include <iostream>
using namespace std;

class Pair
{
public:
    int max, min;
};

Pair minimumMaximum(int arr[], int n)
{
    Pair minmax;
    int i;
    if (n % 2 == 0)
    {
        if (arr[0] > arr[1])
        {
            minmax.max = arr[0];
            minmax.min = arr[1];
        }
        else
        {
            minmax.min = arr[0];
            minmax.max = arr[1];
        }
        i = 2;
    }
    else
    {
        minmax.min = arr[0];
        minmax.max = arr[0];
        i = 1;
    }
    while (i < n - 1)
    {
        if (arr[i] > arr[i + 1])
        {
            if (arr[i] > minmax.max)
            {
                minmax.max = arr[i];
            }
            if (arr[i + 1] < minmax.min)
            {
                minmax.min = arr[i + 1];
            }
        }
        else
        {
            if (arr[i + 1] > minmax.max)
            {
                minmax.max = arr[i + 1];
            }
            if (arr[i] < minmax.min)
            {
                minmax.min = arr[i];
            }
        }
        i += 2;
    }
    return minmax;
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
    Pair ans = minimumMaximum(arr, n);
    cout << ans.max << " : " << ans.min;
    delete[] arr;
    return 0;
}