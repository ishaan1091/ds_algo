#include <bits/stdc++.h>
using namespace std;

void print(vector<int> &arr)
{
    for (auto i : arr)
        cout << i << " ";
    cout << endl;
}

bool binarySearch(vector<int> &arr, int val)
{
    int start = 0, end = arr.size() - 1;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (arr[mid] < val)
        {
            start = mid + 1;
        }
        else if (arr[mid] > val)
        {
            end = mid - 1;
        }
        else
        {
            return true;
        }
    }
    return false;
}

int lowerBound(vector<int> &arr, int val)
{
    int start = 0, end = arr.size() - 1;
    while (start < end)
    {
        int mid = start + (end - start) / 2;
        if (arr[mid] < val)
        {
            start = mid + 1;
        }
        else
        {
            end = mid;
        }
    }
    if (arr[end] < val)
        return -1;
    return end;
}

int upperBound(vector<int> &arr, int val)
{
    int start = 0, end = arr.size() - 1;
    while (start < end)
    {
        int mid = start + (end - start) / 2;
        if (arr[mid] <= val)
        {
            start = mid + 1;
        }
        else
        {
            end = mid;
        }
    }
    if (arr[end] <= val)
        return -1;
    return end;
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0, 3, 3, 3};

    // sort a vector
    sort(arr.begin(), arr.end());
    print(arr);

    // reverse a vector
    reverse(arr.begin(), arr.end());
    print(arr);

    // get sum of elements of vector
    int sum = accumulate(arr.begin(), arr.end(), 0);
    cout << sum << endl;

    // getting maximum or minimum element and their respective positions in the vector
    auto maxIterator = max_element(arr.begin(), arr.end());
    auto minIterator = min_element(arr.begin(), arr.end());
    int maxIdx = maxIterator - arr.begin(), maxVal = *maxIterator;
    int minIdx = minIterator - arr.begin(), minVal = *minIterator;
    cout << maxIdx << " " << maxVal << endl;
    cout << minIdx << " " << minVal << endl;

    // finding in vector
    // returns arr.end() if element not found
    auto it = find(arr.begin(), arr.end(), 6);
    int idx = it - arr.begin(), val = *it;
    cout << idx << " " << val << endl;

    // count numbe of occurences of an element in a vector
    int num_of_occurences = count(arr.begin(), arr.end(), 3);
    cout << num_of_occurences << endl;

    // ########################    BINARY SEARCH FUNCTIONS #############################

    sort(arr.begin(), arr.end());

    // binary search plain and simple
    bool found = binary_search(arr.begin(), arr.end(), 4);
    cout << (found ? "Yes" : "No") << endl;
    found = binary_search(arr.begin(), arr.end(), 40);
    cout << (found ? "Yes" : "No") << endl;

    // lower_bound and upper_bound
    vector<int> arr1 = {1, 2, 3, 3, 3, 4};
    vector<int> arr2 = {1, 2, 3, 4};
    vector<int> arr3 = {1, 2, 4};
    int idx1 = lower_bound(arr1.begin(), arr1.end(), 3) - arr1.begin();
    int idx2 = lower_bound(arr2.begin(), arr2.end(), 3) - arr2.begin();
    int idx3 = lower_bound(arr3.begin(), arr3.end(), 3) - arr3.begin();
    cout << idx1 << " " << arr1[idx1] << endl;
    cout << idx2 << " " << arr2[idx2] << endl;
    cout << idx3 << " " << arr3[idx3] << endl;
    idx1 = upper_bound(arr1.begin(), arr1.end(), 3) - arr1.begin();
    idx2 = upper_bound(arr2.begin(), arr2.end(), 3) - arr2.begin();
    idx3 = upper_bound(arr3.begin(), arr3.end(), 3) - arr3.begin();
    cout << idx1 << " " << arr1[idx1] << endl;
    cout << idx2 << " " << arr2[idx2] << endl;
    cout << idx3 << " " << arr3[idx3] << endl;
    idx1 = lower_bound(arr3.begin(), arr3.end(), 0) - arr3.begin();
    idx2 = upper_bound(arr3.begin(), arr3.end(), 4) - arr3.begin();
    cout << idx1 << " " << arr3[idx1] << endl;
    cout << idx2 << " " << arr3[idx2] << endl;

    // Custom binary search functions implemented by me above
    cout << "Output of Custom function from here : " << endl;
    found = binarySearch(arr, 4);
    cout << (found ? "Yes" : "No") << endl;
    found = binarySearch(arr, 40);
    cout << (found ? "Yes" : "No") << endl;
    idx1 = lowerBound(arr1, 3);
    idx2 = lowerBound(arr2, 3);
    idx3 = lowerBound(arr3, 3);
    cout << idx1 << " " << arr1[idx1] << endl;
    cout << idx2 << " " << arr2[idx2] << endl;
    cout << idx3 << " " << arr3[idx3] << endl;
    idx1 = upperBound(arr1, 3);
    idx2 = upperBound(arr2, 3);
    idx3 = upperBound(arr3, 3);
    cout << idx1 << " " << arr1[idx1] << endl;
    cout << idx2 << " " << arr2[idx2] << endl;
    cout << idx3 << " " << arr3[idx3] << endl;
    idx1 = lowerBound(arr3, 0);
    idx2 = lowerBound(arr3, 5);
    cout << idx1 << " " << arr3[idx1] << endl;
    cout << idx2 << " " << arr3[idx2] << endl;
    idx1 = upperBound(arr3, 0);
    idx2 = upperBound(arr3, 4);
    cout << idx1 << " " << arr3[idx1] << endl;
    cout << idx2 << " " << arr3[idx2] << endl;

    return 0;
}