#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007

int numDecodings(string s)
{
    long first = 1, second = (s[0] == '*' ? 9 : (s[0] == '0' ? 0 : 1));
    for (int i = 1; i < s.length(); i++)
    {
        long temp = second;
        if (s[i] == '*')
        {
            second = 9 * second % mod;
            if (s[i - 1] == '1')
            {
                second = (second + 9 * first) % mod;
            }
            else if (s[i - 1] == '2')
            {
                second = (second + 6 * first) % mod;
            }
            else if (s[i - 1] == '*')
            {
                second = (second + 15 * first) % mod;
            }
        }
        else
        {
            second = (s[i] == '0' ? 0 : second);
            if (s[i - 1] == '1')
            {
                second = (second + first) % mod;
            }
            else if (s[i - 1] == '2' && (s[i] - '0') <= 6)
            {
                second = (second + first) % mod;
            }
            else if (s[i - 1] == '*')
            {
                second = (second + ((s[i] - '0') <= 6 ? 2 : 1) * first) % mod;
            }
        }
        first = temp;
    }
    return second;
}

int main()
{
    string s;
    cin >> s;
    int ans = numDecodings(s);
    cout << ans << endl;
    return 0;
}