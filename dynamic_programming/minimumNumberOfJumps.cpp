#include <bits/stdc++.h>
using namespace std;

int minJumps(int arr[], int n)
{
    if (arr[0] == 0 || n == 0)
    {
        return -1;
    }
    vector<int> jumps(n, INT_MAX);
    jumps[n - 1] = 0;
    for (int i = n - 2; i >= 0; i--)
    {
        for (int j = 1; j <= arr[i] && i + j <= n - 1; j++)
        {
            if (jumps[i + j] != -1)
            {
                jumps[i] = min(jumps[i], jumps[i + j]);
            }
        }
        if (jumps[i] != INT_MAX)
        {
            jumps[i]++;
        }
        else
        {
            jumps[i] = -1;
        }
    }
    return jumps[0];
}

int main()
{
    int n;
    cin >> n;
    int *jumps = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> jumps[i];
    }
    int ans = minJumps(jumps, n);
    cout << ans << endl;
    delete[] jumps;
    return 0;
}