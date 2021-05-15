#include <bits/stdc++.h>
using namespace std;

int countSubarrays(int arr[], int n)
{
    // Your code here
    unordered_map<int, int> m;
    m[0] = -1;
    int sum = 0;
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        if (m.count(sum) > 0)
        {
            count += m[sum];
            m[sum]++;
        }
        else
        {
            m[sum] = 1;
        }
    }
    return count;
}

int main()
{
    int arr[] = {15, -2, 2, -8, 1, 7, 10, 23};
    cout << countSubarrays(arr, 8) << endl;
    return 0;
}