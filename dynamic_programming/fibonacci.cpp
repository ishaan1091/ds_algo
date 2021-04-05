#include <bits/stdc++.h>
using namespace std;

int fibMemoization(int n, vector<int> &fibonacci)
{
    if (n == 0 || n == 1)
    {
        fibonacci[n] = n;
        return fibonacci[n];
    }
    if (fibonacci[n] != -1)
    {
        return fibonacci[n];
    }
    fibonacci[n] = fibMemoization(n - 1, fibonacci) + fibMemoization(n - 2, fibonacci);
    return fibonacci[n];
}

int fibTabulation(int n)
{
    vector<int> fibonacci(n + 1, -1);
    fibonacci[0] = 0;
    fibonacci[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        fibonacci[i] = fibonacci[i - 1] + fibonacci[i - 2];
    }
    return fibonacci[n];
}

int main()
{
    int n;
    cin >> n;
    vector<int> fibonacci(n + 1, -1);
    int ans = fibMemoization(n, fibonacci);
    cout << "Solution using Memoization: " << ans << endl;
    ans = fibTabulation(n);
    cout << "Solution using Tabulation: " << ans << endl;
    return 0;
}