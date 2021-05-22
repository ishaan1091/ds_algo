#include <bits/stdc++.h>
using namespace std;

int paintHouse(vector<vector<int>> &arr)
{
    int red = arr[0][0];
    int blue = arr[0][1];
    int green = arr[0][2];
    for (int i = 1; i < arr.size(); i++)
    {
        int newRed = min(blue, green) + arr[i][0];
        int newBlue = min(red, green) + arr[i][1];
        int newGreen = min(blue, red) + arr[i][2];
        red = newRed;
        blue = newBlue;
        green = newGreen;
    }
    return min(red, min(blue, green));
}

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> costs(n, vector<int>(3));
    for (int i = 0; i < n; i++)
    {
        cin >> costs[i][0];
        cin >> costs[i][1];
        cin >> costs[i][2];
    }
    int ans = paintHouse(costs);
    cout << ans << endl;
    return 0;
}