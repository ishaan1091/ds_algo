#include <bits/stdc++.h>
using namespace std;

unsigned long long int catalan(int n)
{
    unsigned long long int C[n + 1];
    memset(C, 0, sizeof(C));
    C[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            C[i] += C[j] * C[i - j - 1];
        }
    }
    return C[n];
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << catalan(i) << endl;
    }
    return 0;
}