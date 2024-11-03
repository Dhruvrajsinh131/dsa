#include <iostream>
using namespace std;

void fun(int a[])
{
    cout << a[0] << " ";
}

void square(int *p)
{
    int a = 10;
    p = &a;
    *p = (*p) * (*p);

    cout << a << endl;
}

int main()
{
    // char s[] = "hello";
    // char *p = s;
    // cout << s[0] << " " << p[0];

    // char b[] = "xyz";
    // char *c = &b[1];
    // // c++;

    // cout << c << endl;

    // int a[] = {1, 2, 3, 4};
    // fun(a + 1);
    // cout << a[0];

    int a = 10;
    square(&a);
    cout << a << endl;
}