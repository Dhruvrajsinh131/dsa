#include <iostream>
using namespace std;
#include <queue>

int main()
{
    queue<int> q;

    q.push(234);
    q.push(2);
    q.push(456);
    q.push(76);

    cout << q.front() << endl;
    q.pop();
    cout << q.front() << endl;
    cout << q.size() << endl;
    cout << q.empty() << endl;
}