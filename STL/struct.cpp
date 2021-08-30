#include <bits/stdc++.h>
using namespace std;

// A data type where you can store values like — {int, double, string, int[]} . So to create such a data type we use Struct

struct node
{
    string str;
    double d;
    char c;

    // Constructor to initialize values for node
    node(string str_, double d_, char c_)
    {
        str = str_;
        d = d_;
        c = c_;
    }
};

// Also now that you have seen how we can use struct to create such data types the doubt that
// comes to our mind is that can't we use classes to do the same
// The answer to this is yes we can use classes to do the same and in fact it even better to use classes to do the same
// because classes have more features than structs can offer.

int main()
{
    node ishaan("HI", 10.0, '?');
    cout << ishaan.str << endl;
    cout << ishaan.d << endl;
    cout << ishaan.c << endl;
    return 0;
}