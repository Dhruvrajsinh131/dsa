#include <iostream>
using namespace std;

int my_fun(int x, int *py, int **ppz)
{
    int y, z;
    **ppz += 1; // c= 5
    z = **ppz;  // z = 5
    *py += 2;   // c  =7
    y = *py;    // y = 7

    x += 3; // x = 7

    return x + y + z;
}

int main()
{
    int c, *b, **a;

    c = 4;
    b = &c;
    a = &b;

    cout << my_fun(c, b, a);

    return 0;
}