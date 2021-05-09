#include <bits/stdc++.h>
using namespace std;

vector<int> countDistinct(int arr[], int n, int k)
{
    //code here.
    vector<int> output;
    unordered_map<int, int> m;
    int i = 0;
    for (; i < k - 1; i++)
    {
        if (m.count(arr[i]) > 0)
        {
            m[arr[i]]++;
        }
        else
        {
            m[arr[i]] = 1;
        }
    }
    for (; i < n; i++)
    {
        if (m.count(arr[i]) > 0)
        {
            m[arr[i]]++;
        }
        else
        {
            m[arr[i]] = 1;
        }
        output.push_back(m.size());
        m[arr[i - k + 1]]--;
        if (m[arr[i - k + 1]] == 0)
            m.erase(arr[i - k + 1]);
    }
    return output;
}

int main()
{
    int arr[] = {1, 2, 1, 3, 4, 2, 3};
    vector<int> output = countDistinct(arr, 7, 4);
    for (auto i : output)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}