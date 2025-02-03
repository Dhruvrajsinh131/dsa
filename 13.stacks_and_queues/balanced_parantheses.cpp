#include <iostream>
using namespace std;
#include <stack>

bool isBalanced(const string &str)
{
    stack<char> s1;

    for (int i = 0; i < str.length(); i++)
    {
        char currentVal = str[i];

        if (currentVal == '(' || currentVal == '[' || currentVal == '{')
        {
            s1.push(currentVal);
        }
        else
        {
            if (!s1.empty() || ((s1.top() == '(' && currentVal == ')') || (s1.top() == '{' && currentVal == '}') || (s1.top() == '[' && currentVal == ']')))
            {
                s1.pop();
            }
            else
            {
                return false;
            }
        }
    }
    return s1.empty();
}

int main()
{
    string str = "{[()]}";

    bool isBool = isBalanced(str);
    cout << isBool;
}
