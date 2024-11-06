#include <iostream>
using namespace std;

int i;

void g()
{
    cout << i << endl;
    i++;
}
void f()
{
    cout << i << endl;
    i++;
    g();
}

int main()
{
    i = 69;
    f();
    cout << i << endl;
}