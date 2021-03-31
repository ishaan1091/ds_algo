#include <bits/stdc++.h>
using namespace std;

void printMazePath(int n, int sr, int sc, int dr, int dc, string ans)
{
    if (sr > dr || sc > dc)
    {
        return;
    }
    if (sr == dr && sc == dc)
    {
        cout << ans << endl;
    }
    printMazePath(n, sr + 1, sc, dr, dc, ans + 'v');
    printMazePath(n, sr, sc + 1, dr, dc, ans + 'h');
}

int main()
{
    int n, sr, sc, dr, dc;
    cin >> n >> sr >> sc >> dr >> dc;
    printMazePath(n, sr, sc, dr, dc, "");
    return 0;
}