#include <iostream>
using namespace std;

class DyncmicArray
{

    int *data;

    int nextIndex;
    int size;

public:
    DyncmicArray()
    {
        data = new int[5];
        nextIndex = 0;
        size = 5;
    }

    DyncmicArray(DyncmicArray const &d)
    {
        // this->data = d.data; Shallow Copy

        // Deepcopy
        this->data = new int[d.size];

        for (int i = 0; i < d.nextIndex; i++)
        {
            this->data[i] = d.data[i];
        }

        this->nextIndex = d.nextIndex;
        this->size = d.size;
    }

    void add(int element)
    {
        if (nextIndex == size)
        {

            int *newArr = new int[2 * size];

            for (int i = 0; i < size; i++)
            {
                newArr[i] = data[i];
            }

            delete[] data;
            data = newArr;
            size *= 2;
        }

        data[nextIndex] = element;
        nextIndex++;
    }

    int get(int i)
    {

        if (i < nextIndex)
        {

            return data[i];
        }
        else
        {
            return -1;
        }
    }

    void add(int i, int element)
    {

        if (i < nextIndex)
        {

            data[i] = element;
        }
        else if (i == nextIndex)
        {
            add(element);
        }
        else
        {
            return;
        }
    }

    void print()
    {
        for (int i = 0; i < nextIndex; i++)
        {
            cout << data[i] << " ";
        }
        cout << endl;
    }

    void operator=(DyncmicArray const &d)
    {
        this->data = new int[d.size];

        for (int i = 0; i < d.nextIndex; i++)
        {
            this->data[i] = d.data[i];
        }

        this->nextIndex = d.nextIndex;
        this->size = d.size;
    }
};

int main()
{

    DyncmicArray d1;

    d1.add(10);
    d1.add(20);
    d1.add(30);
    d1.add(40);
    d1.add(50);
    d1.add(60);

    d1.print();

    DyncmicArray d2(d1);

    // d1.add(1, 100);
    d2.print();
    DyncmicArray d3;

    d3 = d1;

    d1.add(1, 100);
    d3.print();

    d1.print();
}