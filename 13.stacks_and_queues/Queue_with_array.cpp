#include <iostream>
using namespace std;

template <typename T>

class Queue
{
    int firstIndex;
    int nextIndex;
    int capacity;
    int size;
    T *data;

public:
    Queue()
    {
        data = new T[4];
        firstIndex = -1;
        nextIndex = 0;
        capacity = 4;
        size = 0;
    }

    int getSize()
    {
        return size;
    }

    bool isEmpty()
    {
        return size == 0;
    }

    T front()
    {
        if (isEmpty())
        {
            cout << "Queue is Empty . " << endl;
            return 0;
        }
        return data[firstIndex];
    }

    T dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue is Empty . " << endl;
            return 0;
        }
        T ans = data[firstIndex];

        firstIndex = (firstIndex + 1) % capacity;
        size--;

        if (size == 0)
        {
            firstIndex = -1;
            nextIndex = 0;
        }
        return ans;
    }

    void enqueue(T elem)
    {
        if (size == capacity)
        {
            int j = 0;
            T *newData = new T[2 * capacity];
            for (int i = firstIndex; i < capacity; i++)
            {
                newData[j] = data[i];
            }
            for (int i = 0; i < firstIndex; i++)
            {
                newData[j] = data[i];
            }

            firstIndex = 0;
            nextIndex = capacity;
            delete[] data;
            data = newData;
            capacity *= 2;
        }

        data[nextIndex] = elem;
        nextIndex = (nextIndex + 1) % capacity;
        size++;

        if (firstIndex == -1)
        {
            firstIndex = 0;
        }
        if (size == 0)
        {
            firstIndex = -1;
            nextIndex = 0;
        }
    }
};

int main()
{
    Queue<int> q1;

    q1.enqueue(32);
    q1.enqueue(234);
    q1.enqueue(235);
    q1.enqueue(356);

    cout << q1.dequeue() << endl;
    cout << q1.dequeue() << endl;
    cout << q1.dequeue() << endl;
    cout << q1.dequeue() << endl;
    cout << q1.dequeue() << endl;
}