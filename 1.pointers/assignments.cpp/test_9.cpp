#include <iostream>
using namespace std;

int main()
{
    int ***r, **q, *p, i = 8;

    p = &i; // p > i;
    (*p)++; // i = 9

    q = &p;  // q > p
    (**q)++; // i =10

    r = &q; // r > q

    cout << *p << " " << **q << " " << ***r;
    return 0;
}