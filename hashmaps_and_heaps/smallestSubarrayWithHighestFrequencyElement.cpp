#include <bits/stdc++.h>
using namespace std;

vector<int> smallestSubsegment(int arr[], int n)
{
    unordered_map<int, int> freqMap;
    unordered_map<int, int> firstOccurence;
    int highFreq = 0, start = 0, end = 0, l = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        if (firstOccurence.count(arr[i]))
        {
            freqMap[arr[i]]++;
        }
        else
        {
            freqMap[arr[i]] = 1;
            firstOccurence[arr[i]] = i;
        }
        int len = i - firstOccurence[arr[i]] + 1;
        if (freqMap[arr[i]] > highFreq)
        {
            highFreq = freqMap[arr[i]];
            start = firstOccurence[arr[i]];
            end = i;
            l = len;
        }
        else if (freqMap[arr[i]] == highFreq)
        {
            if (len < l)
            {
                l = len;
                start = firstOccurence[arr[i]];
                end = i;
            }
        }
    }
    vector<int> output;
    for (int i = start; i <= end; i++)
    {
        output.push_back(arr[i]);
    }
    return output;
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    vector<int> output = smallestSubsegment(arr, n);
    for (auto i : output)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}