#include <bits/stdc++.h>
using namespace std;

// Note I accidently did this question twice findPath1, findPathUtil1 are the first solution
// findPath2, findPathUtil2, isSafe2 are the second solution
// Essentially the algorithm used in both is the same just different ways of writing the same things

void findPathUtil1(vector<vector<int>> &m, int n, int r, int c, string str, vector<string> &ans, vector<vector<bool>> &visited)
{
    if (r >= n || c >= n || r < 0 || c < 0)
    {
        return;
    }
    if (r == n - 1 && c == n - 1 && m[r][c] == 1)
    {
        ans.push_back(str);
        return;
    }
    if (m[r][c] == 0 || visited[r][c])
    {
        return;
    }
    visited[r][c] = true;
    if (r > 0)
    {
        findPathUtil1(m, n, r - 1, c, str + "U", ans, visited);
    }
    if (r < n - 1)
    {
        findPathUtil1(m, n, r + 1, c, str + "D", ans, visited);
    }
    if (c > 0)
    {
        findPathUtil1(m, n, r, c - 1, str + "L", ans, visited);
    }
    if (c < n - 1)
    {
        findPathUtil1(m, n, r, c + 1, str + "R", ans, visited);
    }
    visited[r][c] = false;
}

vector<string> findPath1(vector<vector<int>> &m, int n)
{
    vector<vector<bool>> visited(n, vector<bool>(n, false));
    vector<string> ans;
    findPathUtil1(m, n, 0, 0, "", ans, visited);
    sort(ans.begin(), ans.end());
    return ans;
}

bool isSafe2(vector<vector<int>> &m, int n, int r, int c)
{
    if (r >= 0 && c >= 0 && m[r][c] == 1 && r < n && c < n)
    {
        return true;
    }
    return false;
}

vector<string> findPathUtil2(vector<vector<int>> &m, int n, int r, int c, vector<vector<bool>> &visited)
{
    if (r == n - 1 && c == n - 1 && !visited[r][c] && m[r][c] == 1)
    {
        vector<string> ans;
        ans.push_back("");
        return ans;
    }
    vector<string> ans;
    if (isSafe2(m, n, r, c))
    {
        visited[r][c] = true;
        if (r < n - 1 && !visited[r + 1][c])
        {
            vector<string> temp = findPathUtil2(m, n, r + 1, c, visited);
            for (int i = 0; i < temp.size(); i++)
            {
                ans.push_back("D" + temp[i]);
            }
        }
        if (r > 0 && !visited[r - 1][c])
        {
            vector<string> temp = findPathUtil2(m, n, r - 1, c, visited);
            for (int i = 0; i < temp.size(); i++)
            {
                ans.push_back("U" + temp[i]);
            }
        }
        if (c < n - 1 && !visited[r][c + 1])
        {
            vector<string> temp = findPathUtil2(m, n, r, c + 1, visited);
            for (int i = 0; i < temp.size(); i++)
            {
                ans.push_back("R" + temp[i]);
            }
        }
        if (c > 0 && !visited[r][c - 1])
        {
            vector<string> temp = findPathUtil2(m, n, r, c - 1, visited);
            for (int i = 0; i < temp.size(); i++)
            {
                ans.push_back("L" + temp[i]);
            }
        }
        visited[r][c] = false;
    }
    return ans;
}

vector<string> findPath2(vector<vector<int>> &m, int n)
{
    vector<vector<bool>> visited(n, vector<bool>(n, false));
    vector<string> ans = findPathUtil2(m, n, 0, 0, visited);
    sort(ans.begin(), ans.end());
    return ans;
}

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> m(n, vector<int>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> m[i][j];
        }
    }
    vector<string> ans = findPath1(m, n);
    for (auto i : ans)
    {
        cout << i << endl;
    }
    ans = findPath2(m, n);
    for (auto i : ans)
    {
        cout << i << endl;
    }
    return 0;
}