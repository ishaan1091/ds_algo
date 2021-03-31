#include <bits/stdc++.h>
using namespace std;

vector<string> getKeypadCombination(string arr[], string n)
{
    if (n.length() == 0)
    {
        vector<string> ans;
        ans.push_back("");
        return ans;
    }
    vector<string> ans = getKeypadCombination(arr, n.substr(1));
    vector<string> output;
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < arr[n[0] - 48].length(); j++)
        {
            output.push_back(arr[n[0] - 48][j] + ans[i]);
        }
    }
    return output;
}

int main()
{
    string n;
    cin >> n;
    string arr[10];
    for (int i = 1; i < 10; i++)
    {
        cin >> arr[i];
    }
    cin >> arr[0];
    vector<string> v = getKeypadCombination(arr, n);
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
    cout << v.size() << endl;
    return 0;
}