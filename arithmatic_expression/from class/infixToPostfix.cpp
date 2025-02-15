#include <bits/stdc++.h>
using namespace std;

stack<char> S;

int priority(char s)
{
    if (s == '^')
    {
        return 100;
    }
    else if (s == '*' || s == '/')
    {
        return 50;
    }
    else if (s == '+' || s == '-')
    {
        return 20;
    }
    else
        return 0;
}

int main()
{
    string infix, postfix = "";
    cin >> infix; // (A+B/C*(D+E)-F) | (5+6/2*(8+4)-7)

    for (size_t i = 0; i < infix.size(); i++)
    {
        char symbol = infix[i];
        if (isupper(symbol) || islower(symbol) || isdigit(symbol)) // if (symbol >= 'A' && symbol <= 'Z')
        {
            postfix = postfix + symbol;
        }
        else if (symbol == '(')
        {
            S.push(symbol);
        }
        else if (symbol == ')')
        {
            while (!S.empty() && S.top() != '(')
            {
                postfix = postfix + S.top();
                S.pop();
            }
            S.pop();
        }
        else
        {
            while (!S.empty() && priority(S.top()) >= priority(symbol))
            {
                postfix = postfix + S.top();
                S.pop();
            }
            S.push(symbol);
        }
    }
    while (!S.empty())
    {
        postfix = postfix + S.top();
        S.pop();
    }
    cout << postfix << endl;

    return 0;
}