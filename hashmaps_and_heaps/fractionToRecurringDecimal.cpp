#include <bits/stdc++.h>
using namespace std;

string fractionToDecimal(int num, int den)
{
    string ans = "";
    if ((num > 0 && den < 0) || (num < 0 && den > 0))
        ans += "-";
    num = abs(num);
    den = abs(den);
    long long q = num / den;
    long long r = num % den;
    ans += to_string(abs(q));
    if (r != 0)
    {
        ans += ".";
        unordered_map<int, int> decimals;
        long long i = ans.length();
        while (r != 0)
        {
            if (decimals.count(r))
            {
                ans += ")";
                ans = ans.substr(0, decimals[r]) + "(" + ans.substr(decimals[r]);
                break;
            }
            else
            {
                decimals[r] = i;
                r *= 10;
                q = r / den;
                r = r % den;
                ans += to_string(abs(q));
            }
            i++;
        }
    }
    return ans;
}

int main()
{
    int numerator, denominator;
    cin >> numerator >> denominator;
    string ans = fractionToDecimal(numerator, denominator);
    cout << ans << endl;
    return 0;
}