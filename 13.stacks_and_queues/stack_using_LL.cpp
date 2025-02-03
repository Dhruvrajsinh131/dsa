#include <iostream>
using namespace std;
#include "Node.cpp"

template <typename T>

class Stack
{
    int size;
    Node<T> *head;

public:
    Stack()
    {
        this->size = 0;
        this->head = nullptr;
    }

    T push(T data)
    {
        Node<T> *newNode = new Node<T>(data);
        if (this->head == nullptr)
        {
            this->head = newNode;
        }
        else
        {

            newNode->next = this->head;
            this->head = newNode;
        }
        this->size++;

        return data;
    }

    T top()
    {
        if (!head)
        {
            throw runtime_error("Stack is empty!");
        }

        return head->data;
    }
    T pop()
    {
        if (!head)
        {
            throw runtime_error("Stack is empty!");
        }
        T tempdata = head->data;

        Node<T> *nodeToDelete = head;
        head = head->next;

        delete nodeToDelete;

        this->size--;
        return tempdata;
    }

    bool isEmpty()
    {
        return this->size == 0;
    }

    int getSize()
    {
        return this->size;
    }

    void printStack()
    {
        Node<T> *temp = head;

        while (temp != nullptr)
        {

            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    ~Stack()
    {
        while (!isEmpty())
        {
            pop();
        }
    }
};

int main()
{
    Stack<int> *s1 = new Stack<int>();

    s1->push(57);
    s1->push(75);
    s1->push(234);
    s1->push(567);
    s1->push(56);

    s1->printStack();

    cout << "Element at top = " << s1->top() << endl;
    cout << "Removed Element from top = " << s1->pop() << endl;
    cout << "Is Stack Empty = " << s1->isEmpty() << endl;
    cout << "Stack Size = " << s1->getSize() << endl;

    s1->printStack();
}