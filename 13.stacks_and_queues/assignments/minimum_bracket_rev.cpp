#include <iostream>
#include <stack>
using namespace std;

int countBracketReversals(string expression)
{
    int n = expression.length();

    if (n % 2 != 0)
        return -1;

    stack<char> s;

    for (char c : expression)
    {
        if (c == '{')
        {
            s.push(c);
        }
        else
        {
            if (!s.empty() && s.top() == '{')
            {
                s.pop();
            }
            else
            {
                s.push(c);
            }
        }
    }

    int openCount = 0, closeCount = 0;
    while (!s.empty())
    {
        if (s.top() == '{')
            openCount++;
        else
            closeCount++;
        s.pop();
    }

    return (openCount + 1) / 2 + (closeCount + 1) / 2;
}

int main()
{
    string expression;
    cin >> expression;
    cout << countBracketReversals(expression) << endl;
    return 0;
}
