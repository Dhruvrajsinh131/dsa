#include <iostream>
using namespace std;

int main()
{
    const int p = 5;
    int const *q = &p;
    // p++; gives error because of read only access

    cout << q << endl;
    q++; // points to next locaiom
    cout << q << endl;
    // (*q)++; gives error because of read only access
}