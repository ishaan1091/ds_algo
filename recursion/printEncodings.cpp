#include <bits/stdc++.h>
using namespace std;

void printEncodings(string str, string ans)
{
    if (str[0] == '0')
    {
        return;
    }
    if (str.length() == 0)
    {
        cout << ans << endl;
        return;
    }
    else if (str.length() == 1)
    {
        if (str[0] == '0')
        {
            return;
        }
        else
        {
            int charCode = str[0] - 48;
            char letter = 'a' + charCode - 1;
            ans += letter;
            cout << ans << endl;
            return;
        }
    }
    int charCode = str[0] - 48;
    if (charCode > 0)
    {
        char letter = 'a' + charCode - 1;
        string remainingString = str.substr(1);
        printEncodings(remainingString, ans + letter);
    }

    string charCodeStr = str.substr(0, 2);
    string remainingString = str.substr(2);
    charCode = stoi(charCodeStr);
    if (charCode <= 26)
    {
        char letter = 'a' + charCode - 1;
        printEncodings(remainingString, ans + letter);
    }
}

int main()
{
    string str;
    cin >> str;
    printEncodings(str, "");
    return 0;
}