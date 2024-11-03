#include <iostream>
using namespace std;

void print(int *p)
{
    cout << *p << endl;
}

void incrementPointer(int *p) // pass by value
{

    p = p + 1;

    cout << p << endl;
}

void increment(int *p)

{
    (*p)++;
}

// int sum(int a[], int size)
int sum(int *a, int size) // int a[] and int * a both are same as passed in function arguments
{

    cout << sizeof(a) << endl;
    int sum = 0;

    for (int i = 0; i < size; i++)
    {
        sum += a[i];
    }

    return sum;
}

int main()
{

    // int a = 10;
    // int *ptr = &a;

    // print(ptr);

    // cout << ptr << endl;
    // incrementPointer(ptr);
    // cout << ptr << endl;

    // cout << *ptr << endl;
    // increment(ptr);
    // cout << *ptr << endl;

    int a[] = {1, 2, 5, 456, 456};
    cout << sizeof(a) << endl;
    cout << sum(a + 3, 2);
}
