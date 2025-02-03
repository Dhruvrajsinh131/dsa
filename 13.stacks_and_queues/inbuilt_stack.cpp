#include <iostream>
using namespace std;
#include <stack>

int main()
{
    stack<int> s1;

    s1.push(32);
    s1.push(34);
    s1.push(456);
    s1.push(1);

    cout << s1.top() << endl;
    s1.pop();
    cout << s1.top() << endl;
    s1.pop();
}
