#include <iostream>
using namespace std;
#include <queue>

void rev_queue(queue<int> &q)
{
    if (q.empty())
    {
        return;
    }

    int valFront = q.front();
    q.pop();

    rev_queue(q);

    q.push(valFront);
}

void print_queue(queue<int> q)
{
    cout << "Queue = ";
    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
}

int main()
{
    queue<int> q1;

    q1.push(1);
    q1.push(2);
    q1.push(3);
    q1.push(4);

    print_queue(q1);
    cout << endl;

    rev_queue(q1);
    print_queue(q1);
    cout << endl;
}