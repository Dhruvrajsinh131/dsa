#include <iostream>
using namespace std;

// int i;

// void g()
// {
//     cout << i << endl;
//     i++;
// }
// void f()
// {
//     cout << i << endl;
//     i++;
//     g();
// }

int x = 1;

void print()
{
    int x = 2;
    {
        int x = 3;
        cout << x << endl;
    }
}

int main()
{
    // i = 69;
    // f();
    // cout << i << endl;

    print();
    return 0;
}