#include <bits/stdc++.h>
using namespace std;

void printMazePathWithJumps(int n, int sr, int sc, int dr, int dc, string ans)
{
    if (sr == dr && sc == dc)
    {
        cout << ans << endl;
        return;
    }
    for (int i = 1; i <= dr - sr; i++)
    {
        printMazePathWithJumps(n, sr + i, sc, dr, dc, ans + 'v' + to_string(i));
    }
    for (int i = 1; i <= dc - sc; i++)
    {
        printMazePathWithJumps(n, sr, sc + i, dr, dc, ans + 'h' + to_string(i));
    }
    for (int i = 1; i <= dr - sr && i <= dc - sc; i++)
    {
        printMazePathWithJumps(n, sr + i, sc + i, dr, dc, ans + 'd' + to_string(i));
    }
}

int main()
{
    int n, sr, sc, dr, dc;
    cin >> n >> sr >> sc >> dr >> dc;
    printMazePathWithJumps(n, sr, sc, dr, dc, "");
    return 0;
}