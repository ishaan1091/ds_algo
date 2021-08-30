#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    s = "Ishaan Kamra";

    // Commonly used C++ iterators
    // begin(), end(), rbegin(), rend();
    // begin - points to the starting point of the data structure/ STL container
    // end - points to the empty address right after the last element of the data structure/ STL container
    // rbegin - points to the last point or the reverse beginning of the data structure/ STL container
    // rend - points to the empty address right before the first element of the data structure/ STL container
    cout << "Printing using begin and end iterators : ";
    for (auto it = s.begin(); it != s.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
    cout << "Printing using rbegin and rend iterators : ";
    for (auto it = s.rbegin(); it != s.rend(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;

    // size of string
    // you can use length() or size() both are synonymous functions with different names and are exactly the same
    cout << "Length of string : " << s.size() << endl;
    cout << "Length of string : " << s.length() << endl;

    // front element of the string
    cout << "Front character of the string : " << s.front() << endl;

    // back element of the string
    cout << "Last character of the string : " << s.back() << endl;

    // check if string is empty or not
    cout << "Checking if string is empty or not : " << (s.empty() ? "Yes" : "No") << endl;

    // pop_back() used to remove the last element of the string
    s.pop_back();
    cout << "String after removing the last character of the string : " << s << endl;

    // Inserting element 'ele' at index i or Use i = 0 for inserting at front
    char ele = 'X';
    int i = 1;
    s.insert(s.begin() + i, ele);
    cout << "Inserting character at a given index in string : " << s << endl;

    // Remove an element at index i
    i = 1;
    s.erase(s.begin() + i);
    cout << "Removing element at index i : " << s << endl;

    // Remove elements from i to j-1;
    i = 0;
    int j = 3;
    s.erase(s.begin() + i, s.begin() + j);
    cout << "Removing all elements from i to j-1 : " << s << endl;

    // Remove all elements with value = x from s
    char x = 'a';
    s.erase(remove(s.begin(), s.end(), x), s.end());
    cout << "After removing all elements with value 'a' from s : " << s << endl;

    //  clear() function is used to remove all the elements of the vector container, thus making it size 0
    s.clear();
    cout << "After using clear() function : " << s << endl;

    s = "Ishaan Kamra";

    // finding an element or string in a given string, return -1 if not present
    // use second argument if you want to find starting from a given index
    cout << "Position of 'a' in the string : " << s.find('a') << endl;
    cout << "Position of 'Kam' in the string : " << s.find("Kam") << endl;
    cout << "Position of 'a' in the string starting from the 6 index : " << s.find('a', 6) << endl;

    // string to integer and integer to string
    // stoi() - string to integer
    // to_string() - integer to string
    cout << stoi("123") << " " << typeid(stoi("123")).name() << endl;
    cout << to_string(123) << " " << typeid(to_string(123)).name() << endl;

    // ####################################    STRING STREAMS #####################################

    // Counting Words in a sentence using string stream
    string str = "Hello World";
    stringstream ss(str); /* In this way, you can initialise a string stream with str's value */
    int count = 0;
    string word;
    /* str >> var will perform as if we are doing cin>>var with the input as the value of 'ss'
    If you do ss >> word, think of it like ss throws it's first word into 'word' */
    while (ss >> word)
    {
        count++;
    }
    cout << "Number of words in the given sentence : " << str << " : " << count << endl;

    // Converting String to Numbers
    string str1 = "12345";
    stringstream ss1(str1);
    /* str >> var will perform as if we are doing cin>>var with the input as the value of 'ss' */
    int y;
    ss1 >> y; /* y will now have value 12345 */
    cout << "String converted to number using string stream : " << y << endl;

    // Split functionality with custom delimiter
    /* For this we take help of getline function to change the default delimiter from ' ' to  '-'
    getline(istream& is, string& str, char delim); */
    stringstream ss2("123-456-789");
    vector<string> v;
    string word1;
    while (getline(ss2, word1, '-'))
    {
        v.push_back(word1);
    }
    /* v will now have value : {"123", "456", "789"} */
    cout << "Splitting using string stream with custom delimiter : ";
    for (auto i : v)
        cout << i << " ";
    cout << endl;

    return 0;
}