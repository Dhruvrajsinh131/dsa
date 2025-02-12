#include <iostream>
using namespace std;
#include <stack>

bool checkRedundant(string expression)
{
    stack<char> s;

    for (int i = 0; expression[i]; i++)
    {
        char ch = expression[i];

        if (ch == ')')
        {
            int count = 0;

            while (!s.empty() && s.top() != '(')
            {

                char top = s.top();
                s.pop();

                if (top == '+' || top == '-' || top == '%' || top == '/' || top == '*')
                {
                    count++;
                }
            }

            if (!s.empty())
            {
                s.pop();
            }

            if (count == 0)
            {
                return true;
            }
        }
        else
        {
            s.push(ch);
        }
    }
    return false;
}

int main()
{
    string expression = "(a+(b+c))";

    if (checkRedundant(expression))
    {
        cout << "Contains Redundant" << endl;
    }
    else
    {
        cout << "Does not contain redundant" << endl;
    }
}