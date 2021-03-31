#include <bits/stdc++.h>
using namespace std;

struct cell
{
    int r;
    int c;
    int steps;
};

bool isValid(int r, int c, int n)
{
    if (r >= 0 && c >= 0 && r < n && c < n)
    {
        return true;
    }
    return false;
}

int minStepToReachTarget(vector<int> &KnightPos, vector<int> &TargetPos, int n)
{
    KnightPos[0]--;
    KnightPos[1]--;
    TargetPos[0]--;
    TargetPos[1]--;
    vector<vector<bool>> visited(n, vector<bool>(n, false));
    queue<cell> q;
    q.push({KnightPos[0], KnightPos[1], 0});
    visited[KnightPos[0]][KnightPos[1]];
    vector<vector<int>> dxy = {{2, 1}, {2, -1}, {-2, 1}, {-2, -1}, {1, 2}, {1, -2}, {-1, 2}, {-1, -2}};
    while (!q.empty())
    {
        cell front = q.front();
        q.pop();
        if (front.r == TargetPos[0] && front.c == TargetPos[1])
        {
            return front.steps;
        }
        for (int i = 0; i < dxy.size(); i++)
        {
            int nr = front.r + dxy[i][0];
            int nc = front.c + dxy[i][1];
            if (isValid(nr, nc, n) && !visited[nr][nc])
            {
                visited[nr][nc] = true;
                q.push({nr, nc, front.steps + 1});
            }
        }
    }
    return -1;
}

int main()
{
    int n;
    cin >> n;
    vector<int> KnightPos(2);
    cin >> KnightPos[0] >> KnightPos[1];
    vector<int> TargetPos(2);
    cin >> TargetPos[0] >> TargetPos[1];
    int ans = minStepToReachTarget(KnightPos, TargetPos, n);
    cout << ans << endl;
    return 0;
}