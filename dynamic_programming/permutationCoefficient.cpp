#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007

int nPr(int n, int r)
{
    long long int P[r + 1];
    memset(P, 0, sizeof(P));
    P[0] = 1;
    for (int i = 0; i <= n; i++)
    {
        for (int j = min(i, r); j > 0; j--)
        {
            P[j] = P[j] % mod + ((P[j - 1] % mod) * (j % mod)) % mod;
            P[j] %= mod;
        }
    }
    return P[r];
}

int main()
{
    int n, r;
    cin >> n >> r;
    cout << nPr(n, r) << endl;
    return 0;
}