#include <stack>
#include <string>

/*
 * for better understanding of two distinct numbers (if they are multi-digit)
 * each number is separated with ' ' (space character) [only for postfix]
 */

class Operation {

    static int priority(char s)
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

public:
    static std::string to_postfix(std::string infix)
    {
        std::string postfix = "";
        std::stack<char> Stack;
        for (size_t i = 0; i < infix.size(); i++)
        {
            char symbol = infix[i];
            if (isupper(symbol) || islower(symbol) || isdigit(symbol))
            {
                postfix += symbol;
            }
            else if (symbol == '(')
            {
                Stack.push(symbol);
            }
            else if (symbol == ')')
            {
                while (!Stack.empty() && Stack.top() != '(')
                {
                    postfix.push_back(' ');
                    postfix += Stack.top();
                    Stack.pop();
                }
                Stack.pop();
            }
            else // if any operators
            {
                while (!Stack.empty() && priority(Stack.top()) >= priority(symbol))
                {
                    postfix.push_back(' ');
                    postfix += Stack.top();
                    Stack.pop();
                }
                Stack.push(symbol);
                postfix.push_back(' ');
            }
        }
        while (!Stack.empty())
        {
            postfix.push_back(' ');
            postfix += Stack.top();
            Stack.pop();
        }
        return postfix;
    }

    static double evaluate_postfix(std::string postfix)
    {
        std::stack<double> Stack;
        for (size_t i = 0; i < postfix.size(); i++)
        {
            char symbol = postfix[i];
            if (symbol == ' ') continue;
            else if (isdigit(symbol))
            {
                std::string number = { symbol };
                while (isdigit(postfix[i+1]))
                {
                    number += postfix[++i];
                }
                Stack.push(std::stod(number));
            }
            else
            {
                double a = Stack.top(); Stack.pop();
                double b = Stack.top(); Stack.pop();
                double x;
                     if (symbol == '+') x = b + a;
                else if (symbol == '-') x = b - a;
                else if (symbol == '*') x = b * a;
                else if (symbol == '/') x = b / a;
                Stack.push(x);
            }
        }
        return Stack.top();
    }

};