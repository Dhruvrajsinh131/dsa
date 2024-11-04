#include <iostream>
using namespace std;

void updateValue(int *p)
{
    *p = 610 % 255;
}

void func(int i, int &j, int p)
{
    i++;
    j++;
    p++;
}

int main()
{
    // char ch = 'A';
    // updateValue((int *)&ch);
    // cout << ch;

    int i = 10;
    int j = 6;
    int &p = i;

    func(i, j, p);

    cout << i << " " << j << " " << p;
}

// d -> ASSCI VALUE = 100