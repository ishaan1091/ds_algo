#include <bits/stdc++.h>
using namespace std;

bool subsetSum(vector<int> &arr, int target)
{
    if (target == 0)
        return 0;
    int n = arr.size();
    vector<vector<bool>> dp(n + 1, vector<bool>(target + 1));
    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < target + 1; j++)
        {
            if (i == 0 && j == 0)
            {
                dp[i][j] = true;
            }
            else if (i == 0)
            {
                dp[i][j] = false;
            }
            else if (j == 0)
            {
                dp[i][j] = true;
            }
            else
            {
                if (dp[i - 1][j] == true)
                {
                    dp[i][j] = true;
                }
                else
                {
                    int val = arr[i - 1];
                    if (j >= val)
                    {
                        if (dp[i - 1][j - val] == true)
                        {
                            dp[i][j] = true;
                        }
                    }
                }
            }
        }
    }
    return dp[n][target];
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
    int target;
    cin >> target;
    cout << (subsetSum(arr, target) ? "YES" : "NO") << endl;
    return 0;
}