#include <iostream>
#include <bits/stdc++.h>
#include <cstring>
#include <vector>
using namespace std;

void q2(int n)
{
    int x;
    if (n > 1)
    {
        x = 2;
    }
    else
    {
        x = 1;
    }
    for (int j = 5; j > 0; j += x)
    {
        int mid = j / 2, divisor = 0;
        int temp;
        bool found = true;
        for (int i = 1; i <= mid; i++)
        {
            if (j % i == 0)
            {
                divisor++;
                if (divisor != 1)
                {
                    if (i - temp < n)
                    {
                        found = false;
                    }
                }
                temp = i;
            }
        }
        if (j - temp < n)
        {
            found = false;
        }
        divisor++;
        if (divisor < 4)
        {
            found = false;
        }
        if (found == true)
        {
            cout << j << endl;
            break;
        }
    }
}

void q1(int n, string b)
{
    string ans = "1";
    int current = b[0] + 1;
    for (int i = 1; i < n; i++)
    {
        if (current == b[i] + 1)
        {
            ans += "0";
            current = b[i];
        }
        else
        {
            ans += "1";
            current = b[i] + 1;
        }
    }
    cout << ans << endl;
}

int main()
{
    int t;
    cin >> t;
    for (int x = 0; x < t; x++)
    {
        int n;
        cin >> n;
        q2(n);
    }
    return 0;
}
