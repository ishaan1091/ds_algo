#include <bits/stdc++.h>
using namespace std;

class Pair
{
public:
    string path;
    int i;
    int j;
};

Pair makePair(string path, int i, int j)
{
    Pair p;
    p.path = path;
    p.i = i;
    p.j = j;
    return p;
}

void printPaths(vector<int> &vals, vector<int> &weights, int target)
{
    vector<vector<int>> dp(weights.size() + 1, vector<int>(target + 1, 0));
    for (int i = 1; i < dp.size(); i++)
    {
        for (int j = 1; j < dp[0].size(); j++)
        {
            dp[i][j] = dp[i - 1][j];
            if (j >= weights[i - 1])
                dp[i][j] = max(dp[i][j], dp[i - 1][j - weights[i - 1]] + vals[i - 1]);
        }
    }
    cout << dp[weights.size()][target] << endl;
    queue<Pair> q;
    q.push(makePair("", weights.size(), target));
    while (!q.empty())
    {
        Pair front = q.front();
        q.pop();
        if (front.i == 0 || front.j == 0)
        {
            cout << front.path << endl;
            continue;
        }
        if (front.j >= weights[front.i - 1] && dp[front.i - 1][front.j - weights[front.i - 1]] + vals[front.i - 1] > dp[front.i - 1][front.j])
        {
            q.push(makePair(to_string(front.i - 1) + " " + front.path, front.i - 1, front.j - weights[front.i - 1]));
        }
        else
        {
            q.push(makePair(front.path, front.i - 1, front.j));
        }
    }
}

int main()
{
    int n;
    cin >> n;
    vector<int> vals(n);
    vector<int> weights(n);
    for (int i = 0; i < n; i++)
        cin >> vals[i];
    for (int i = 0; i < n; i++)
        cin >> weights[i];
    int target;
    cin >> target;
    printPaths(vals, weights, target);
    return 0;
}