#include <bits/stdc++.h>
using namespace std;

int fun(string &s)
{
    //code here
    int a = 0;
    int ab = 0;
    int abc = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == 'a')
        {
            a = 2 * a + 1;
        }
        else if (s[i] == 'b')
        {
            ab = 2 * ab + a;
        }
        else
        {
            abc = 2 * abc + ab;
        }
    }
    return abc;
}

int main()
{
    string s;
    cin >> s;
    int ans = fun(s);
    cout << ans << endl;
    return 0;
}