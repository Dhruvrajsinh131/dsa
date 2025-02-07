#include <iostream>
using namespace std;
#include "Node.cpp"

class Queue
{
    Node<int> *head;
    Node<int> *tail;
    int size;

public:
    Queue()
    {
        head = nullptr;
        tail = nullptr;
        size = 0;
    }

    int getSize()
    {
        return this->size;
    }

    bool isEmpty()
    {
        return this->head == nullptr;
    }

    int front()
    {
        if (!this->head)
        {
            cout << "Queue is empty" << endl;
            return -1;
        }
        return this->head->data;
    }

    void enqueue(int data)
    {

        Node<int> *newNode = new Node(data);

        if (this->head == nullptr)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = tail->next;
        }
        this->size++;
    }

    int dequeue()
    {
        if (!this->head)
        {
            cout << "Queue is empty" << endl;
            return -1;
        }

        int ans = this->head->data;

        Node<int> *delNode = this->head;

        this->head = this->head->next;

        delete delNode;
        this->size++;

        return ans;
    }
};

int main()
{

    Queue q1;

    q1.enqueue(1);
    q1.enqueue(2);
    q1.enqueue(3);
    q1.enqueue(234);
    q1.enqueue(456);
    q1.enqueue(546);

    cout << q1.front() << endl;
    cout << q1.dequeue() << endl;
    cout << q1.front() << endl;
    cout << q1.dequeue() << endl;
    cout << q1.front() << endl;
    cout << q1.dequeue() << endl;
    cout << q1.dequeue() << endl;
    cout << q1.dequeue() << endl;
    cout << q1.dequeue() << endl;
    cout << q1.dequeue() << endl;
}