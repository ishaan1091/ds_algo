#include <bits/stdc++.h>
using namespace std;

void printSubsequence(string str, string ans)
{
    if (str.length() == 0)
    {
        cout << ans << endl;
        return;
    }
    char firstLetter = str[0];
    string remainingString = str.substr(1);
    printSubsequence(remainingString, ans + "");
    printSubsequence(remainingString, ans + firstLetter);
}

int main()
{
    string str;
    cin >> str;
    printSubsequence(str, "");
    return 0;
}