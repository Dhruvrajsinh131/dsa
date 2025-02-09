#include <iostream>
using namespace std;
#include <queue>

void rev_queue(queue<int> &q, int lastElem)
{
    if (q.front() == lastElem)
    {
        return;
    }

    int valFront = q.front();
    q.pop();

    rev_queue(q, lastElem);

    q.push(valFront);
}

void print_queue(queue<int> q)
{
    if (q.empty())
    {
        cout << "Queue = ";
        return;
    }

    int val = q.front();
    q.pop();

    print_queue(q);
    cout << val << " ";
}

int main()
{
    queue<int> q1;

    q1.push(1);
    q1.push(2);
    q1.push(3);
    q1.push(4);

    int lastElem = q1.back();

    print_queue(q1);
    cout << endl;

    rev_queue(q1, lastElem);
    print_queue(q1);
    cout << endl;
}