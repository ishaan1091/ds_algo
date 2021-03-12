#include <bits/stdc++.h>
using namespace std;

vector<int> allIndicesOfOccurence(int arr[], int n, int k)
{
    if (n == 0)
    {
        vector<int> v;
        return v;
    }
    vector<int> v = allIndicesOfOccurence(arr, n - 1, k);
    if (arr[n - 1] == k)
    {
        v.push_back(n - 1);
    }
    return v;
}

int main()
{
    int n, k;
    cin >> n >> k;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    vector<int> v = allIndicesOfOccurence(arr, n, k);
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    delete[] arr;
    return 0;
}