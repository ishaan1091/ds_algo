#include <bits/stdc++.h>
using namespace std;

int countBinaryStrings(int n)
{
    int first = 1, second = 1;
    for (int i = 1; i < n; i++)
    {
        int up = second;
        int down = first + second;
        first = up;
        second = down;
    }
    return first + second;
}

int main()
{
    int n;
    cin >> n;
    cout << countBinaryStrings(n) << endl;
    return 0;
}