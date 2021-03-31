#include <bits/stdc++.h>
using namespace std;

void printKeypadCombinations(string num, string ans, string codes[])
{
    if (num.length() == 0)
    {
        cout << ans << "  ";
        return;
    }
    char firstNumber = num[0];
    int firstNum = firstNumber - 48;
    string remainingString = num.substr(1);
    for (int i = 0; i < codes[firstNum].length(); i++)
    {
        printKeypadCombinations(remainingString, ans + codes[firstNum][i], codes);
    }
}

int main()
{
    string codes[10] = {"?/", ".;", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    string num;
    cin >> num;
    printKeypadCombinations(num, "", codes);
    return 0;
}