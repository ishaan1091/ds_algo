#include <bits/stdc++.h>
using namespace std;

int linearSearchIterative(vector<int> &arr, int x)
{
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] == x)
            return i;
    }
    return -1;
}

int linearSearchRecursive(vector<int> &arr, int x, int idx = 0)
{
    if (idx == arr.size())
        return -1;
    if (arr[idx] == x)
        return idx;
    return linearSearchRecursive(arr, x, idx + 1);
}

int binarySearchIterative(vector<int> &arr, int x)
{
    int start = 0, end = arr.size() - 1;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (arr[mid] < x)
            start = mid + 1;
        else if (arr[mid] > x)
            end = mid - 1;
        else
            return mid;
    }
    return -1;
}

int binarySearchRecursive(vector<int> &arr, int x, int start = 0, int end = INT_MIN)
{
    if (end == INT_MIN)
        end = arr.size();
    if (start > end)
        return -1;
    int mid = start + (end - start) / 2;
    if (arr[mid] < x)
        return binarySearchRecursive(arr, x, mid + 1, end);
    else if (arr[mid] > x)
        return binarySearchRecursive(arr, x, start, mid - 1);
    return mid;
}

bool binarySearchIterativeAlternativeUtil(vector<int> &arr, int x, int idx)
{
    if (arr[idx] >= x)
        return true;
    return false;
}

int binarySearchIterativeAlternative(vector<int> &arr, int x)
{
    int start = 0, end = arr.size() - 1, mid = 0;
    while (start < end)
    {
        mid = start + (end - start) / 2;
        if (arr[mid] >= x)
            end = mid;
        else
            start = mid + 1;
    }
    if (arr[end] == x)
        return mid;
    return -1;
}

int lowerBound(vector<int> &arr, int x)
{
    int start = 0, end = arr.size() - 1;
    while (start < end)
    {
        int mid = start + (end - start) / 2;
        if (arr[mid] < x)
        {
            start = mid + 1;
        }
        else if (arr[mid] >= x)
        {
            end = mid;
        }
    }
    if (arr[end] < x)
        return arr.size();
    return end;
}

int upperBound(vector<int> &arr, int x)
{
    int start = 0, end = arr.size() - 1, mid;
    while (start < end)
    {
        mid = start + (end - start) / 2;
        if (arr[mid] <= x)
            start = mid + 1;
        else
            end = mid;
    }
    if (arr[end] < x)
        return arr.size();
    return end;
}

void selectionSortIterative(vector<int> &arr)
{
    for (int i = 0; i < arr.size() - 1; i++)
    {
        int minIdx = i;
        for (int j = i + 1; j < arr.size(); j++)
        {
            if (arr[minIdx] > arr[j])
                minIdx = j;
        }
        swap(arr[i], arr[minIdx]);
    }
}

void selectionSortRecursive(vector<int> &arr, int idx = 0)
{
    if (idx == arr.size())
        return;
    int minIdx = idx;
    for (int j = idx + 1; j < arr.size(); j++)
    {
        if (arr[minIdx] > arr[j])
            minIdx = j;
    }
    swap(arr[idx], arr[minIdx]);
    selectionSortRecursive(arr, idx + 1);
}

void bubbleSortIterative(vector<int> &arr)
{
    for (int i = 0; i < arr.size() - 1; i++)
    {
        for (int j = 0; j < arr.size() - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
        }
    }
}

void bubbleSortRecursive(vector<int> &arr, int end = INT_MIN)
{
    if (end == 0)
        return;
    if (end == INT_MIN)
        end = arr.size() - 1;
    for (int i = 0; i < end; i++)
    {
        if (arr[i] > arr[i + 1])
            swap(arr[i], arr[i + 1]);
    }
    bubbleSortRecursive(arr, end - 1);
}

void insertionSortIterative(vector<int> &arr)
{
    for (int i = 1; i < arr.size(); i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (arr[i] < arr[j])
            {
                int temp = arr[i];
                for (int k = i; k > j; k--)
                {
                    arr[k] = arr[k - 1];
                }
                arr[j] = temp;
                break;
            }
        }
    }
}

void insertionSortRecursive(vector<int> &arr, int idx = 0)
{
    if (idx == arr.size())
        return;
    for (int j = 0; j < idx; j++)
    {
        if (arr[idx] < arr[j])
        {
            int temp = arr[idx];
            for (int k = idx; k > j; k--)
            {
                arr[k] = arr[k - 1];
            }
            arr[j] = temp;
            break;
        }
    }
    insertionSortRecursive(arr, idx + 1);
}

void printArr(vector<int> &arr)
{
    for (auto i : arr)
        cout << i << " ";
    cout << endl;
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    vector<int> tempArr = arr;
    int x = 0, y = 0, ans = 0;
    cout << "Enter element to use for searching : ";
    cin >> x;
    cout << "Enter element to use for finding upper and lower bound : ";
    cin >> y;
    ans = linearSearchIterative(arr, x);
    cout << "Position of element using Linear Search Iterative : " << ans << endl;
    ans = linearSearchRecursive(arr, x);
    cout << "Position of element using Linear Search Recursive : " << ans << endl;
    sort(tempArr.begin(), tempArr.end());
    ans = binarySearchIterative(tempArr, x);
    cout << "Position of element using Binary Search Iterative : " << ans << endl;
    ans = binarySearchRecursive(tempArr, x);
    cout << "Position of element using Binary Search Recursive : " << ans << endl;
    ans = binarySearchIterativeAlternative(tempArr, x);
    cout << "Position of element using Binary Search Iterative Alternative approach : " << ans << endl;
    ans = lowerBound(tempArr, y);
    cout << "Position, Value of the lower bound element of " << y << " : " << ans << " , " << (ans < n ? tempArr[ans] : -1) << endl;
    ans = upperBound(tempArr, y);
    cout << "Position, Value of the upper bound element of " << y << " : " << ans << " , " << (ans < n ? tempArr[ans] : -1) << endl;
    tempArr = arr;
    selectionSortIterative(tempArr);
    cout << "Sorting using Selection Sort Iterative : ";
    printArr(tempArr);
    tempArr = arr;
    selectionSortRecursive(tempArr);
    cout << "Sorting using Selection Sort Recursive : ";
    printArr(tempArr);
    tempArr = arr;
    bubbleSortIterative(tempArr);
    cout << "Sorting using Bubble Sort Iterative : ";
    printArr(tempArr);
    tempArr = arr;
    bubbleSortRecursive(tempArr);
    cout << "Sorting using Bubble Sort Recursive : ";
    printArr(tempArr);
    tempArr = arr;
    insertionSortIterative(tempArr);
    cout << "Sorting using Insertion Sort Iterative : ";
    printArr(tempArr);
    tempArr = arr;
    insertionSortRecursive(tempArr);
    cout << "Sorting using Insertion Sort Recursive : ";
    printArr(tempArr);
    return 0;
}
