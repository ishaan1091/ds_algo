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

int nextGap(int gap)
{
    if (gap <= 1)
    {
        return 0;
    }
    return (gap / 2) + (gap % 2);
}

// Optimal approach
void mergeUsingGapMethod(int arr1[], int arr2[], int n, int m)
{
    int i, j, gap = n + m;
    for (gap = nextGap(gap); gap > 0; gap = nextGap(gap))
    {
        for (i = 0; i + gap < n; i++)
        {
            if (arr1[i] > arr1[i + gap])
            {
                swap(arr1[i], arr1[i + gap]);
            }
        }
        for (j = gap > n ? gap - n : 0; i < n && j < m; i++, j++)
        {
            if (arr1[i] > arr2[j])
            {
                swap(arr1[i], arr2[j]);
            }
        }
        if (j < m)
        {
            for (j = 0; j + gap < m; j++)
            {
                if (arr2[j] > arr2[j + gap])
                {
                    swap(arr2[j], arr2[j + gap]);
                }
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