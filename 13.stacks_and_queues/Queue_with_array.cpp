#include <iostream>
using namespace std;

template <typename T>
class Queue
{

    T *data;
    int firstIndex;
    int nextIndex;
    int size;
    int capacity;

public:
    Queue(int s)
    {
        data = new T[s];
        nextIndex = 0;
        firstIndex = -1;
        size = 0;
        capacity = s;
    }

    int getSize()
    {
        return size;
    }

    bool isEmpty()
    {
        return size == 0;
    }

    void enqueue(T element)
    {
        if (size == capacity)
        {

            T *newData = new T[2 * capacity];
            int j = 0;
            for (int i = firstIndex; i < capacity; i++)
            {
                newData[j] = data[i];
                j++;
            }

            for (int i = 0; i < firstIndex; i++)
            {
                newData[j] = data[i];
                j++;
            }
            firstIndex = 0;
            nextIndex = capacity;
            delete[] data;
            data = newData;
            capacity *= 2;

            // cout << "Queue Full !" << endl;
            // return;
        }
        data[nextIndex] = element;
        nextIndex = (nextIndex + 1) % capacity;

        if (firstIndex == -1)
        {
            firstIndex = 0;
        }

        size++;
        if (size == 0)
        {
            firstIndex = -1;
            nextIndex = 0;
        }
    }

    T front()
    {
        if (isEmpty())
        {
            cout << "Queue is empty ! " << endl;
            return 0;
        }
        return data[firstIndex];
    }

    T dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue is empty ! " << endl;
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
};

int main()
{
    Queue<int> q1(10);

    q1.enqueue(3243);
    q1.enqueue(56);
    q1.enqueue(12);
    q1.enqueue(546);
    q1.enqueue(176);
    q1.enqueue(354);
    q1.enqueue(56);
    q1.enqueue(12);
    q1.enqueue(546);
    q1.enqueue(176);
    q1.enqueue(354);
    q1.enqueue(56);
    q1.enqueue(12);
    q1.enqueue(546);
    q1.enqueue(176);
    q1.enqueue(354);

    cout << q1.dequeue() << endl;
    cout << q1.dequeue() << endl;
    cout << q1.dequeue() << endl;
    cout << q1.dequeue() << endl;
    cout << q1.dequeue() << endl;
    cout << q1.dequeue() << endl;
    cout << q1.dequeue() << endl;
    cout << q1.dequeue() << endl;
    cout << q1.dequeue() << endl;
    cout << q1.dequeue() << endl;
    cout << q1.dequeue() << endl;
    cout << q1.dequeue() << endl;
    cout << q1.dequeue() << endl;
    cout << q1.dequeue() << endl;
    cout << q1.dequeue() << endl;
    cout << q1.dequeue() << endl;
    cout << q1.dequeue() << endl;
    cout << q1.dequeue() << endl;
    cout << q1.dequeue() << endl;
}