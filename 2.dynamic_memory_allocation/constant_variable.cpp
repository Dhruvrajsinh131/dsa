#include <iostream>
using namespace std;

void g(int const &a)
{
    // a++; gives error
}
void f(const int *p)
{
    // (*p)++; gives error
}

int main()
{

    // constant int
    const int i = 10;
    const int i2 = 12;

    // const  reference from non cost int

    int j = 12;
    const int &k = j;
    j++;
    // k++; Gives error , reference is const

    // const  reference from  cost int
    int j2 = 12;
    const int &k2 = j2;
    // j2++; gives error
    // k2++; gives error

    // reference from a const int
    int const j3 = 123;
    // int &k3 = j3; gives error

    int const i11 = 12;

    // int *p = &i11; Gives error
    int const *p = &i11; // is valid
    // (*p)++; Gives Error can not change const pointer

    int j11 = 234;
    int const *p2 = &j11;
    // (*p2)++; Gives error
    cout << *p2 << endl;
    j11++;
    cout << *p2 << endl;

    int vari = 10;
    int varj = 56;

    int const *ptr = &vari;

    ptr = &varj;
}
