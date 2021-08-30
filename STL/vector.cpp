#include <bits/stdc++.h>
using namespace std;

void print(vector<int> &arr)
{
    cout << "Elements : ";
    for (auto i : arr)
        cout << i << " ";
    cout << endl;
}

int main()
{
    // if declaring an int/double/char arr[] inside main it can have a maximum size of 10^6
    // and if declaring bool arr in main then max size can be 10^7
    // While if you declare it globally that is outside the int main() then it can have a maximum size
    // of 10^7 and for bool arr declared globally max size can be 10^8
    // These rules are same for vector as well.
    // If we try to exceed these limitations we get a Segmentation Fault Error

    vector<int> arr(10);

    // fill arr from start_pos to end_pos with value x we use - arr.fill(start_pos, end_pos, x)
    fill(arr.begin(), arr.end(), 5);
    print(arr);

    // Commonly used C++ iterators
    // begin(), end(), rbegin(), rend();
    // begin - points to the starting point of the data structure/ STL container
    // end - points to the empty address right after the last element of the data structure/ STL container
    // rbegin - points to the last point or the reverse beginning of the data structure/ STL container
    // rend - points to the empty address right before the first element of the data structure/ STL container
    for (auto it = arr.begin(); it != arr.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
    for (auto it = arr.rbegin(); it != arr.rend(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;

    // size of array
    cout << arr.size() << endl;

    // front element of the array
    cout << arr.front() << endl;

    // back element of the array
    cout << arr.back() << endl;

    // check if array is empty or not
    cout << (arr.empty() ? "Yes" : "No") << endl;

    // push_back() used to insert element at end of vector
    arr.push_back(1);
    print(arr);

    // pop_back() used to remove the last element of the vector
    arr.pop_back();
    print(arr);

    // copy the entire arr into arr2
    vector<int> arr2(arr.begin(), arr.end());
    print(arr2);

    // copy the first k elements of arr into arr3
    int k = 2;
    vector<int> arr3(arr.begin(), arr.begin() + k);
    print(arr3);

    // Inserting element 'ele' at index i or Use i = 0 for inserting at front
    int ele = -1;
    int i = 1;
    arr.insert(arr.begin() + i, ele);
    print(arr);

    // Inserting the elements of vector v to the end of vector arr
    vector<int> v = {6, 7, 8, 8, 10};
    arr.insert(arr.end(), v.begin(), v.end());
    print(arr);

    // Remove an element at index i
    i = 1;
    arr.erase(arr.begin() + i);
    print(arr);

    // Remove elements from i to j-1;
    i = 0;
    int j = 3;
    arr.erase(arr.begin() + i, arr.begin() + j);
    print(arr);

    // Remove all elements with value = x from arr
    int x = 8;
    arr.erase(remove(arr.begin(), arr.end(), x), arr.end());
    print(arr);

    //  clear() function is used to remove all the elements of the vector container, thus making it size 0
    arr.clear();
    print(arr);

    return 0;
}