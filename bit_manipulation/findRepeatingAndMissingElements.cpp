#include <bits/stdc++.h>
using namespace std;

void findMissingAndRepeatingElements(vector<int> &arr)
{
    int n = arr.size();
    int res = 0;
    for (auto i : arr)
        res ^= i;
    for (int i = 1; i <= n; i++)
        res ^= i;
    int i = 0;
    while (!(res & (1 << i)))
        i++;
    vector<int> a;
    vector<int> b;
    for (auto j : arr)
    {
        if (j & (1 << i))
            a.push_back(j);
        else
            b.push_back(j);
    }
    for (int j = 1; j <= n; j++)
    {
        if (j & (1 << i))
            a.push_back(j);
        else
            b.push_back(j);
    }
    int resA = 0, resB = 0;
    for (auto j : a)
        resA ^= j;
    for (auto j : b)
        resB ^= j;
    for (auto j : arr)
    {
        if (j == resA)
        {
            cout << "Repeating Number : " << resA << endl;
            cout << "Missing Number : " << resB << endl;
            break;
        }
        else if (j == resB)
        {
            cout << "Repeating Number : " << resB << endl;
            cout << "Missing Number : " << resA << endl;
            break;
        }
    }
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    findMissingAndRepeatingElements(arr);
    return 0;
}