#include <bits/stdc++.h>
using namespace std;

bool printPairWithEqualSum(vector<int> &arr)
{
    unordered_set<int> sums;
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = i + 1; j < arr.size(); j++)
        {
            if (sums.count(arr[i] + arr[j]))
                return true;
            sums.insert(arr[i] + arr[j]);
        }
    }
    return false;
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << (printPairWithEqualSum(arr) ? "true" : "false") << endl;
    return 0;
}