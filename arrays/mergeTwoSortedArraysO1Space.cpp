#include <iostream>
using namespace std;

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

// Better approach than brute force but not optimal
void mergeUsingInsertionSortMethod(int arr1[], int arr2[], int n, int m)
{
    int i = 0, j = 0;
    while (i < n && j < m)
    {
        if (arr1[i] <= arr2[j])
        {
            i++;
        }
        else
        {
            swap(arr1[i++], arr2[j]);
            for (int k = m - 1; k > j; k--)
            {
                if (arr2[k] < arr2[j])
                {
                    int temp = arr2[j];
                    for (int p = j; p < k; p++)
                    {
                        arr2[p] = arr2[p + 1];
                    }
                    arr2[k] = temp;
                    break;
                }
            }
        }
    }
}

// Optimal approach
int nextGap(int gap)
{
    if (gap <= 1)
    {
        return 0;
    }
    return (gap / 2) + (gap % 2);
}

void merge(long long arr1[], long long arr2[], int n, int m)
{
    // code here
    for (int gap = (n + m) / 2; gap >= 1; gap = nextGap(gap))
    {
        int i = 0, j = gap;
        for (; j < n; i++, j++)
        {
            if (arr1[i] > arr1[j])
                swap(arr1[i], arr1[j]);
        }
        for (; i < n && j < n + m; i++, j++)
        {
            if (arr1[i] > arr2[j - n])
                swap(arr1[i], arr2[j - n]);
        }
        for (; i < n + m && j < n + m; i++, j++)
        {
            if (arr2[i - n] > arr2[j - n])
                swap(arr2[i - n], arr2[j - n]);
        }
    }
}
}

int main()
{
    int arr1[5] = {1, 3, 4, 9, 10};
    int arr2[3] = {2, 7, 8};
    int n = 5, m = 3;
    mergeUsingGapMethod(arr1, arr2, n, m);
    for (int i = 0; i < n; i++)
    {
        cout << arr1[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < m; i++)
    {
        cout << arr2[i] << " ";
    }
    return 0;
}