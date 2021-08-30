#include <bits/stdc++.h>
using namespace std;

// "using namespace std;" here refers to using the namespace in which there are
// all the general functions we use in C++ like cin, cout, etc.

// In fact we can create our own namespace as well

namespace ishaan
{
    int val = 50;
    int getVal()
    {
        return val * 10;
    }
}

int main()
{
    double val = 10.0;
    cout << val << endl; // prints 10.0

    cout << ishaan::getVal() << endl; // prints 500
    return 0;
}