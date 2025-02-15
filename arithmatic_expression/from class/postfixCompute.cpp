#include <bits/stdc++.h>
using namespace std;

stack<int> res;

int main()
{
    string postfix = "562/84+*+7-";
    //cin >> postfix;

    for (size_t i = 0; i < postfix.size(); i++)
    {
        char symbol = postfix[i];
        if (isdigit(symbol)) res.push(symbol - '0');
        else
        {
            int a = res.top(); res.pop();
            int b = res.top(); res.pop();
            int x;
                 if (symbol == '+') x = b + a;
            else if (symbol == '-') x = b - a;
            else if (symbol == '*') x = b * a;
            else if (symbol == '/') x = b / a;
            res.push(x);
        }
    }
    cout << res.top();

    return 0;
}