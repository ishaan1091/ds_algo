#include <bits/stdc++.h>
using namespace std;

void printStairPath(int n, string ans)
{
    if (n < 0)
    {
        return;
    }
    if (n == 0)
    {
        cout << ans << endl;
        return;
    }
    printStairPath(n - 1, ans + "1");
    printStairPath(n - 2, ans + "2");
    printStairPath(n - 3, ans + "3");
}

int main()
{
    int n;
    cin >> n;
    printStairPath(n, "");
    return 0;
}