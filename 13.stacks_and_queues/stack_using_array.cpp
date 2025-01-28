#include <iostream>
using namespace std;

class StackUsingArray
{
    int *data;
    int nextIndex;
    int capacity;

public:
    StackUsingArray()
    {
        this->capacity = 4;
        this->data = new int[4];
        this->nextIndex = 0;
    }

    int size()
    {
        return nextIndex;
    }

    bool isEmpty()
    {
        return this->nextIndex == 0;
    }

    void push(int element)
    {
        if (this->capacity == nextIndex)
        {
            int *newData = new int[2 * capacity];
            for (int i = 0; i < capacity; i++)
            {
                newData[i] = data[i];
            }

            capacity *= 2;

            delete[] data;

            data = newData;
        }
        this->data[nextIndex] = element;
        this->nextIndex++;
    }

    int pop()
    {

        if (this->isEmpty())
        {
            cout << "The stack is empty" << endl;
            return INT_MIN;
        }
        this->nextIndex--;

        return data[nextIndex];
    }

    int top()
    {
        if (this->isEmpty())
        {
            cout << "The stack is empty" << endl;
            return INT_MIN;
        }
        return this->data[this->nextIndex - 1];
    }

    void printStack()
    {

        cout << "Stack : ";
        for (int i = 0; i < this->nextIndex; i++)
        {
            cout << this->data[i] << " ";
        }

        cout << endl;
    }
};

int main()
{
    StackUsingArray s;

    s.push(34);
    s.push(5);
    s.push(567);
    s.push(2);
    s.push(2);
    s.push(2);
    s.push(6);
    s.push(45);
    s.push(567);
    s.push(23);
    s.push(56);
    s.push(645);
    s.push(456);
    s.push(2345);
    s.push(34);
    s.push(756);
    s.push(56);

    cout << s.top() << endl;

    cout << s.pop() << endl;
    cout << s.pop() << endl;
    cout << s.pop() << endl;

    cout << s.size() << endl;

    cout << s.isEmpty() << endl;

    s.printStack();
}