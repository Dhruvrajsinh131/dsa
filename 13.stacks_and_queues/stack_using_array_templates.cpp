#include <iostream>
using namespace std;

template <typename T>

class Stack
{
    T *data;
    int nextIndex;
    int capacity;

public:
    Stack()
    {

        this->data = new T[4];
        this->nextIndex = 0;
        this->capacity = 4;
    }

    // push
    void push(T elem)
    {
        if (nextIndex == capacity)
        {
            T *newArr = new T[2 * capacity];

            for (int i = 0; i < capacity; i++)
            {
                newArr[i] = this->data[i];
            }

            capacity *= 2;
            delete[] data;

            data = newArr;
        }

        this->data[nextIndex] = elem;
        this->nextIndex++;
    }
    // size

    int size()
    {
        return this->nextIndex;
    }
    // isEmpty

    bool isEmpty()
    {
        return this->nextIndex == 0;
    }
    // pop
    T pop()
    {
        if (this->isEmpty())
        {
            cout << "Stack is empty" << endl;
            cout << INT_MIN;
        }

        this->nextIndex--;

        return this->data[nextIndex];
    }
    // top

    T top()
    {
        if (this->isEmpty())
        {
            cout << "Stack is empty" << endl;
            cout << INT_MIN;
        }

        return this->data[nextIndex - 1];
    }

    void printStack()
    {
        for (int i = 0; i < nextIndex; i++)
        {
            cout << this->data[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    Stack<int> s1;

    s1.push(23);
    s1.push(34);
    s1.push(6);
    s1.push(47);
    s1.push(12);

    s1.printStack();
    cout << s1.top() << endl;
    cout << s1.pop() << endl;
    s1.printStack();
}