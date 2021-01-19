#include <iostream>
using namespace std;

void printIntersection(int arr1[], int arr2[], int n, int m)
{
    int i = 0, j = 0;
    while (i < n && j < m)
    {
        while (arr1[i] == arr1[i + 1])
        {
            i++;
        }
        while (arr2[j] == arr2[j + 1])
        {
            j++;
        }
        if (arr1[i] < arr2[j])
        {
            i++;
        }
        else if (arr1[i] > arr2[j])
        {
            j++;
        }
        else
        {
            cout << arr1[i++] << " ";
            j++;
        }
    }
    cout << endl;
}

void printUnion(int arr1[], int arr2[], int n, int m)
{
    int i = 0, j = 0;
    while (i < n && j < m)
    {
        while (arr1[i] == arr1[i + 1])
        {
            i++;
        }
        while (arr2[j] == arr2[j + 1])
        {
            j++;
        }
        if (arr1[i] < arr2[j])
        {
            cout << arr1[i++] << " ";
        }
        else if (arr1[i] > arr2[j])
        {
            cout << arr2[j++] << " ";
        }
        else
        {
            cout << arr1[i++] << " ";
            j++;
        }
    }
    while (i < n)
    {
        cout << arr1[i++] << " ";
    }
    while (j < m)
    {
        cout << arr2[j++] << " ";
    }
    cout << endl;
}

int main()
{
    int arr1[6] = {1, 2, 2, 3, 4, 5};
    int arr2[5] = {2, 2, 3, 7, 8};
    int n = 6, m = 5;
    printUnion(arr1, arr2, n, m);
    printIntersection(arr1, arr2, n, m);
    return 0;
}