#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007

int nCr(int n, int r)
{
    if (r > n)
        return 0;
    long long int C[r + 1];
    memset(C, 0, sizeof(C));
    C[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = min(i, r); j > 0; j--)
        {
            C[j] = C[j] % mod + C[j - 1] % mod;
            C[j] %= mod;
        }
    }
    return C[r];
}

int main()
{
    int n, r;
    cin >> n >> r;
    cout << nCr(n, r) << endl;
    return 0;
}