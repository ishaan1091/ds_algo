#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007

long long countWays(int n, int k)
{
    // code here
    if (n == 1)
        return k;
    long long same = k, different = k * (k - 1);
    for (int i = 2; i < n; i++)
    {
        long long newSame = different;
        long long newDifferent = (((same + different) % mod) * (k - 1)) % mod;
        same = newSame;
        different = newDifferent;
    }
    return (same + different) % mod;
}

int main()
{
    int n, k;
    cin >> n >> k;
    long long ans = countWays(n, k);
    cout << ans << endl;
    return 0;
}