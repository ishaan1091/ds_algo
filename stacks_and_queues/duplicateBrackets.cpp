#include <bits/stdc++.h>
using namespace std;

bool duplicateBrackets(string str)
{
    stack<char> s;
    for (auto ch : str)
    {
        if (ch == ')')
        {
            if (s.top() == '(')
                return true;
            while (s.top() != '(')
                s.pop();
            s.pop();
        }
        else
        {
            s.push(ch);
        }
    }
    return false;
}

int main()
{
    string s;
    cin >> s;
    cout << (duplicateBrackets(s) ? "YES" : "NO") << endl;
    return 0;
}