#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007

int countFriendsPairings(int n)
{
    // code here
    long long first = 1, second = 1;
    for (int i = 2; i <= n; i++)
    {
        if (i == 2)
        {
            second = 2;
            continue;
        }
        long long temp = second;
        second = (second + ((i - 1) * first) % mod) % mod;
        first = temp;
    }
    return second;
}

int main()
{
    int n;
    cin >> n;
    cout << countFriendsPairings(n) << endl;
    return 0;
}