#include <iostream>
using namespace std;
#include <stack>

bool isExpressionHasRedundantBrackes(string str)
{
    stack<char> s;

    int count = 0;

    for (int i = 0; str[i] != '\0'; i++)
    {
        char ch = str[i];

        if (ch == ')')
        {
            int count = 0;

            while (!s.empty() && s.top() != '(')
            {
                char top = s.top();
                s.pop();

                if (top == '+' || top == '-' || top == '*' || top == '/')
                {
                    count++;
                }
            }

            if (!s.empty())
            {
                s.pop();
            }

            cout << count << endl;
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

    string expression = "(a+b)";

    if (isExpressionHasRedundantBrackes(expression))
    {
        cout << "Expression  redundant brackets " << endl;
    }
    else
    {
        cout << "Expression does not contain redundant brackets " << endl;
    }
}