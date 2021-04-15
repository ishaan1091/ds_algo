#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007

int countFriendsPairing(int n)
{
    long long int pair[n];
    pair[0] = 1;
    pair[1] = 2;
    for (int i = 2; i < n; i++)
    {
        pair[i] = pair[i - 1] % mod + ((i % mod) * (pair[i - 2] % mod)) % mod;
        pair[i] %= mod;
    }
    return pair[n - 1];
}

int main()
{
    int n;
    cin >> n;
    cout << countFriendsPairing(n) << endl;
    return 0;
}