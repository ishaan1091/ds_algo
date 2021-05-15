#include <bits/stdc++.h>
using namespace std;

vector<string> commonChars(vector<string> &A)
{
    unordered_map<char, int> firstMap;
    unordered_map<char, int> secondMap;
    for (char ch : A[0])
    {
        firstMap[ch]++;
    }
    for (auto i : A)
    {
        for (char ch : i)
        {
            if (firstMap.count(ch))
            {
                secondMap[ch]++;
                firstMap[ch]--;
                if (firstMap[ch] == 0)
                    firstMap.erase(ch);
            }
        }
        firstMap = secondMap;
        secondMap.clear();
    }
    vector<string> output;
    for (auto it : firstMap)
    {
        for (int i = 0; i < it.second; i++)
            output.push_back(string(1, it.first));
    }
    return output;
}

int main()
{
    int n;
    cin >> n;
    vector<string> A(n);
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }
    vector<string> output = commonChars(A);
    for (auto i : output)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}