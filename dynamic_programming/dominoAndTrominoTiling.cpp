#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007

int tilingWithDominos(int n)
{
    int first = 1, second = 1, third = 1;
    for (int i = 2; i <= n; i++)
    {
        if (i == 2)
        {
            third = 2;
            continue;
        }
        int temp = third;
        third = (first + (2 * third) % mod) % mod;
        first = second;
        second = temp;
    }
    return third;
}

int main()
{
    int n;
    cin >> n;
    int ans = tilingWithDominos(n);
    cout << ans << endl;
    return 0;
}