#include <iostream>
using namespace std;

int main()
{
    int i = 65;
    char c = i;

    cout << c << " " << i << endl;

    // int *p = &i;
    // char *pc = (char *)p;

    // cout << p << endl;
    // cout << pc << endl;

    // cout << *p << " " << *pc << endl;
    // cout << *(pc + 1) << endl;
    // cout << *(pc + 2) << endl;

    char *p = &c;
    int *pc = (int *)p;

    cout << *p << " " << *pc << endl;
}