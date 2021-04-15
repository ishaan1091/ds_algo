#include <bits/stdc++.h>
using namespace std;

int carAssembly(vector<vector<int>> &a, vector<vector<int>> &t, vector<int> &e, vector<int> &x)
{
    int n = a[0].size();
    int first, second;
    first = a[0][0] + e[0];
    second = a[1][0] + e[1];
    for (int i = 1; i < n; i++)
    {
        int up = min(first + a[0][i], second + t[1][i] + a[0][i]);
        int down = min(second + a[1][i], first + t[0][i] + a[1][i]);
        first = up;
        second = down;
    }
    return min(first + x[0], second + x[1]);
}

int main()
{
    vector<vector<int>> a = {{4, 5, 3, 2},
                             {2, 10, 1, 4}};
    vector<vector<int>> t = {{0, 7, 4, 5},
                             {0, 9, 2, 8}};
    vector<int> e = {10, 12};
    vector<int> x = {18, 7};
    cout << carAssembly(a, t, e, x) << endl;
    return 0;
}