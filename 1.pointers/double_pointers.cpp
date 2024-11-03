#include <iostream>
using namespace std;

void increment1(int **p) // Does not change anything
{
    p = p + 1;
}

void increment2(int **p) // Change adress of pointer and points to garbage value
{
    *p = *p + 1;
}

void increment3(int **p) // Dereference the pointers and directly change the value.
{
    **p = **p + 1;
}

int main()
{
    int i = 10;
    int *p = &i;
    int **p2 = &p;

    cout << &p << endl;
    cout << p2 << endl;

    cout << p << endl;
    cout << &i << endl;
    cout << *p2 << endl;

    cout << i << endl;
    cout << *p << endl;
    cout << **p2 << endl;

    increment3(p2);

    cout << p << endl;
    cout << *p;
}