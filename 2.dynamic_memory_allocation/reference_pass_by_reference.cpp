#include <iostream>
using namespace std;

void increment(int &i)
{
    i++;
}

int main()
{
    // int i = 10;
    // int &j = i;

    // int k = 6;
    // j = k;

    // i++;

    // cout << j;

    int i = 10;
    increment(i);

    cout << i;
}