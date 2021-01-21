#include <iostream>
#include <unordered_map>
using namespace std;

int countPairs(int arr[], int n, int k)
{
    int ans = 0;
    unordered_map<int, int> arrMap;
    for (int i = 0; i < n; i++)
    {
        int difference = k - arr[i];
        if (arrMap.count(difference) == 1)
        {
            ans += arrMap[difference];
        }
        if (arrMap.count(arr[i]) == 1)
        {
            arrMap[arr[i]] += 1;
        }
        else
        {
            arrMap[arr[i]] = 1;
        }
    }
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
    int k;
    cin >> k;
    int ans = countPairs(arr, n, k);
    cout << ans << endl;
    delete[] arr;
    return 0;
}