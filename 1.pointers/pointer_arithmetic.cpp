#include <iostream>
using namespace std;

int main()
{
    int i = 10;
    int *ptr = &i;

    cout << "before" << ptr << endl;
    ptr++;
    cout << "after" << ptr << endl;
    ptr--;
    cout << "after after" << ptr << endl;
}