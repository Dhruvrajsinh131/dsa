#include <iostream>
using namespace std;
#include <stack>

void rev_stack(stack<int> &s1, stack<int> &s2)
{

    if (s1.empty())
    {
        return;
    }
    int ans = s1.top();

    s1.pop();

    rev_stack(s1, s2);
    s2.push(ans);
}

void printStack(stack<int> s)
{
    if (s.empty())
    {

        cout << "Stack = ";
        return;
    }

    int val = s.top();
    s.pop();
    printStack(s);

    cout << val << " ";
}

int main()
{
    stack<int> s1;
    stack<int> s2;

    s1.push(1);
    s1.push(2);
    s1.push(3);
    s1.push(4);

    printStack(s1);
    cout << endl;
    rev_stack(s1, s2);

    while (!s2.empty())
    {
        s1.push(s2.top());
        s2.pop();
    }

    printStack(s1);
    cout << endl;
}