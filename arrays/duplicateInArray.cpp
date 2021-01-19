#include <iostream>
using namespace std;

int findDuplicate(int nums[], int n)
{
    int ans = -1;
    int *freq = new int[n];
    for (int i = 0; i < n; i++)
    {
        freq[i] = 0;
    }
    for (int i = 0; i < n; i++)
    {
        freq[nums[i]]++;
        if (freq[nums[i]] == 2)
        {
            ans = nums[i];
            break;
        }
    }
    delete[] freq;
    return ans;
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
    int ans = findDuplicate(arr, n);
    cout << ans << endl;
    delete[] arr;
    return 0;
}