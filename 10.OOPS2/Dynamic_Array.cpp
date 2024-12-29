#include <iostream>
using namespace std;

class DynamicArray
{
    int *data;
    int nextIndex;
    int size;

public:
    DynamicArray()
    {
        data = new int[1];
        nextIndex = 0;
        size = 0;
    }

    DynamicArray(DynamicArray const &d)
    {
        data = new int[d.size];
        for (int i = 0; i < d.nextIndex; i++)
        {
            data[i] = d.data[i];
        }

        nextIndex = d.nextIndex;
        size = d.size;
    }

    void add(int element)
    {
        if (nextIndex == size)
        {
            int *newData = new int[2 * size];

            for (int i = 0; i < size; i++)
            {
                newData[i] = data[i];
            }

            delete[] data;
            data = newData;
            size *= 2;
        }

        data[nextIndex] = element;
        nextIndex++;
    }

    void add(int index, int element)
    {
        if (index < nextIndex)
        {
            data[index] = element;
        }
        else if (index < nextIndex)
        {
            add(element);
        }
        else
        {
            return;
        }
    }

    void operator=(DynamicArray const &d)
    {
        data = new int[d.size];
        for (int i = 0; i < d.nextIndex; i++)
        {
            data[i] = d.data[i];
        }

        nextIndex = d.nextIndex;
        size = d.size;
    }

    int getElement(int i) const
    {
        return (i >= 0 && i < nextIndex) ? data[i] : -1;
    }

    void print()
    {
        for (int i = 0; i < nextIndex; i++)
        {
            cout << data[i] << " ";
        }

        cout << endl;
    }
    ~DynamicArray()
    {
        delete[] data;
    }
};

int main()
{
    DynamicArray *arr1 = new DynamicArray();

    arr1->add(2);
    arr1->add(3);
    arr1->add(4);
    arr1->add(5);
    arr1->add(6);

    arr1->print();

    // DynamicArray *arr2 = new DynamicArray(*arr1);

    // arr1->add(1, 69);

    // arr1->print();
    // arr2->print();

    DynamicArray *arr3 = new DynamicArray();

    *arr3 = *arr1;

    arr1->add(2, 69);

    arr1->print();
    arr3->print();

    delete arr1;
    // delete arr2;
    delete arr3;
}