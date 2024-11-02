#include <iostream>
using namespace std;

int main()
{

    int a[10];
    a[0] = 10;
    a[1] = 12;
    cout << a << endl;
    cout << &a << endl;
    cout << &a[0] << endl;

    cout << *a << endl;

    cout << a + 1 << endl;
    cout << *(a + 1) << endl;
    cout << 1 [a] << endl;

    int *p = &a[0];

    cout << p << endl;
    cout << &p << endl;

    cout << sizeof(a) << endl;
    cout << sizeof(p) << endl;

    p = p + 1;

    cout << p << endl;

    // a = a + 1; // invalid syntax  (arrays can not be reasssignedx)
}