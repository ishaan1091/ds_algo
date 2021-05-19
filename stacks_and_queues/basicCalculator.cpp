#include <bits/stdc++.h>
using namespace std;

// This approach works for multi digit positive numbers , negative numbers, etc but fails in cases like
// "1-(+1+1)" where we have a redundant operator
// int precedence(char oprtr)
// {
//     if (oprtr == '+')
//     {
//         return 1;
//     }
//     else if (oprtr == '-')
//     {
//         return 1;
//     }
//     else if (oprtr == '*')
//     {
//         return 2;
//     }
//     else
//     {
//         return 2;
//     }
// }

// int operation(int val1, int val2, char oprtr)
// {
//     if (oprtr == '+')
//     {
//         return val1 + val2;
//     }
//     else if (oprtr == '-')
//     {
//         return val1 - val2;
//     }
//     else if (oprtr == '*')
//     {
//         return val1 * val2;
//     }
//     else
//     {
//         return val1 / val2;
//     }
// }

// int calculate(string s)
// {
//     stack<int> operands;
//     stack<char> operators;
//     operands.push(0);
//     bool prevTermInt = false;
//     for (auto term : s)
//     {
//         if (term == ' ')
//         {
//             prevTermInt = false;
//             continue;
//         }
//         if (term == '+' || term == '-' || term == '*' || term == '/')
//         {
//             while (operators.size() && operators.top() != '(' && precedence(operators.top()) >= precedence(term))
//             {
//                 char oprtr = operators.top();
//                 operators.pop();
//                 int val2 = operands.top();
//                 operands.pop();
//                 int val1 = operands.top();
//                 operands.pop();
//                 operands.push(operation(val1, val2, oprtr));
//             }
//             operators.push(term);
//             prevTermInt = false;
//         }
//         else if (term == '(')
//         {
//             operators.push(term);
//             prevTermInt = false;
//         }
//         else if (term == ')')
//         {
//             while (operators.size() && operators.top() != '(')
//             {
//                 char oprtr = operators.top();
//                 operators.pop();
//                 int val2 = operands.top();
//                 operands.pop();
//                 int val1 = operands.top();
//                 operands.pop();
//                 operands.push(operation(val1, val2, oprtr));
//             }
//             operators.pop();
//             prevTermInt = false;
//         }
//         else
//         {
//             if (prevTermInt)
//             {
//                 operands.top() = operands.top() * 10 + (term - '0');
//             }
//             else
//                 operands.push(term - '0');
//             prevTermInt = true;
//         }
//     }
//     while (!operators.empty())
//     {
//         char oprtr = operators.top();
//         operators.pop();
//         int val2 = operands.top();
//         operands.pop();
//         int val1 = operands.top();
//         operands.pop();
//         operands.push(operation(val1, val2, oprtr));
//     }
//     return operands.top();
// }

int precedence(char oprtr)
{
    if (oprtr == '+')
    {
        return 1;
    }
    else if (oprtr == '-')
    {
        return 1;
    }
    else if (oprtr == '*')
    {
        return 2;
    }
    else
    {
        return 2;
    }
}

int operation(int val1, int val2, char oprtr)
{
    if (oprtr == '+')
    {
        return val1 + val2;
    }
    else if (oprtr == '-')
    {
        return val1 - val2;
    }
    else if (oprtr == '*')
    {
        return val1 * val2;
    }
    else
    {
        return val1 / val2;
    }
}

int calculate(string s)
{
    stack<int> operands;
    stack<char> operators;
    operands.push(0);
    bool prevTermInt = false;
    char prevTerm = ' ';
    for (auto term : s)
    {
        if (term == ' ')
        {
            prevTermInt = false;
            prevTerm = ' ';
            continue;
        }
        if (term == '+' || term == '-' || term == '*' || term == '/')
        {
            if (term == '+' && operators.size() && prevTerm == '(')
            {
                prevTermInt = false;
                prevTerm = '+';
                continue;
            }
            while (operators.size() && operators.top() != '(' && precedence(operators.top()) >= precedence(term))
            {
                char oprtr = operators.top();
                operators.pop();
                int val2 = operands.top();
                operands.pop();
                int val1 = operands.top();
                operands.pop();
                operands.push(operation(val1, val2, oprtr));
            }
            operators.push(term);
            prevTermInt = false;
        }
        else if (term == '(')
        {
            operators.push(term);
            prevTermInt = false;
        }
        else if (term == ')')
        {
            while (operators.size() && operators.top() != '(')
            {
                char oprtr = operators.top();
                operators.pop();
                int val2 = operands.top();
                operands.pop();
                int val1 = operands.top();
                operands.pop();
                operands.push(operation(val1, val2, oprtr));
            }
            operators.pop();
            prevTermInt = false;
        }
        else
        {
            if (prevTermInt)
            {
                operands.top() = operands.top() * 10 + (term - '0');
            }
            else
                operands.push(term - '0');
            prevTermInt = true;
        }
        prevTerm = term;
    }
    while (!operators.empty())
    {
        char oprtr = operators.top();
        operators.pop();
        int val2 = operands.top();
        operands.pop();
        int val1 = operands.top();
        operands.pop();
        operands.push(operation(val1, val2, oprtr));
    }
    return operands.top();
}

int main()
{
    string s = "";
    char c = cin.get();
    while (c != '\n')
    {
        s += c;
        c = cin.get();
    }
    int ans = calculate(s);
    cout << ans << endl;
    return 0;
}