#include <bits/stdc++.h>
using namespace std;

int maxSubstring(string s)
{
    // Your code goes here
    int sum = 0, maxSum = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '1')
            sum += -1;
        else
            sum += 1;
        maxSum = max(sum, maxSum);
        if (sum < 0)
        {
            sum = 0;
        }
    }
    if (maxSum == 0)
        return -1;
    return maxSum;
}

int main()
{
    string s;
    cin >> s;
    int ans = maxSubstring(s);
    cout << ans << endl;
    return 0;
}