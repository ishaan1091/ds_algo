#include <bits/stdc++.h>
using namespace std;

class Pair
{
public:
    string subset;
    int i;
    int j;
};

Pair makePair(string subset, int i, int j)
{
    Pair p;
    p.subset = subset;
    p.i = i;
    p.j = j;
    return p;
}

void printSubsets(vector<int> &arr, int target)
{
    vector<vector<bool>> dp(arr.size() + 1, vector<bool>(target + 1, 0));
    for (int i = 0; i < dp.size(); i++)
    {
        for (int j = 0; j < dp[0].size(); j++)
        {
            if (j == 0)
            {
                dp[i][j] = true;
            }
            else if (i == 0)
            {
                dp[i][j] = false;
            }
            else if (dp[i - 1][j])
            {
                dp[i][j] = true;
            }
            else
            {
                if (j >= arr[i - 1])
                {
                    dp[i][j] = dp[i - 1][j - arr[i - 1]];
                }
            }
        }
    }
    cout << (dp[arr.size()][target] ? "true" : "false") << endl;
    queue<Pair> q;
    if (dp[arr.size()][target])
        q.push(makePair("", arr.size(), target));
    while (!q.empty())
    {
        Pair front = q.front();
        q.pop();
        if (front.i == 0 || front.j == 0)
        {
            cout << front.subset << endl;
            continue;
        }
        if (dp[front.i - 1][front.j])
        {
            q.push(makePair(front.subset, front.i - 1, front.j));
        }
        if (front.j >= arr[front.i - 1] && dp[front.i - 1][front.j - arr[front.i - 1]])
        {
            q.push(makePair(to_string(front.i - 1) + " " + front.subset, front.i - 1, front.j - arr[front.i - 1]));
        }
    }
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
    printSubsets(arr, target);
    return 0;
}