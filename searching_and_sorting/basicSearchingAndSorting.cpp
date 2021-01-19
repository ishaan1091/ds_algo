#include <iostream>
#include <cstring>
using namespace std;

int linearSearch(int arr[], int n, int num)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == num)
        {
            return i;
        }
    }
    return -1;
}

int linearSearchRecursive(int arr[], int n, int num)
{
    if (n == 0)
    {
        return -1;
    }
    if (arr[0] == num)
    {
        return 0;
    }
    int ans = linearSearchRecursive(arr + 1, n - 1, num);
    if (ans != -1)
    {
        return ans + 1;
    }
    return -1;
}

int binarySearch(int arr[], int n, int num)
{
    int start = 0;
    int end = n - 1;
    while (start <= end)
    {
        int mid = (start + end) / 2;
        if (arr[mid] == num)
        {
            return mid;
        }
        else if (arr[mid] < num)
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
    return -1;
}

int binarySearchRecursive(int arr[], int n, int num, int start = 0, int end = -1)
{
    if (end == -1)
    {
        end = n - 1;
    }
    if (start > end)
    {
        return -1;
    }
    int mid = (start + end) / 2;
    if (arr[mid] == num)
    {
        return mid;
    }
    else if (arr[mid] < num)
    {
        return binarySearchRecursive(arr, n, num, mid + 1, end);
    }
    else
    {
        return binarySearchRecursive(arr, n, num, start, mid - 1);
    }
}

void swap(int &a, int &b)
{
    int temp = b;
    b = a;
    a = temp;
}

void selectionSort(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        int min = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min])
            {
                min = j;
            }
        }
        swap(arr[i], arr[min]);
    }
}

void selectionSortRecursive(int arr[], int n)
{
    if (n == 1)
    {
        return;
    }
    int min = 0;
    for (int i = 1; i < n; i++)
    {
        if (arr[i] < arr[min])
        {
            min = i;
        }
    }
    swap(arr[0], arr[min]);
    selectionSortRecursive(arr + 1, n - 1);
}

void bubbleSort(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

void bubbleSortRecursive(int arr[], int n)
{
    if (n == 1)
    {
        return;
    }
    for (int j = 0; j < n; j++)
    {
        if (arr[j] > arr[j + 1])
        {
            swap(arr[j], arr[j + 1]);
        }
    }
    return bubbleSortRecursive(arr, n - 1);
}

void insertionSort(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            int temp = arr[i];
            if (arr[j] > arr[i])
            {
                for (int k = i; k > j; k--)
                {
                    arr[k] = arr[k - 1];
                }
                arr[j] = temp;
            }
        }
    }
}

void insertionSortRecursive(int arr[], int n)
{
    if (n == 0)
    {
        return;
    }
    insertionSortRecursive(arr, n - 1);
    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i] > arr[n - 1])
        {
            int temp = arr[n - 1];
            for (int j = n - 1; j > i; j--)
            {
                arr[j] = arr[j - 1];
            }
            arr[i] = temp;
        }
    }
}

int main()
{
    int arr[10] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    insertionSortRecursive(arr, 10);
    for (int i = 0; i < 10; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    int ans = binarySearchRecursive(arr, 10, 6);
    cout << ans << endl;
    return 0;
}