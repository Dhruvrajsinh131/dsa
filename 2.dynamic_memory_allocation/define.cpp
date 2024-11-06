#include <iostream>
using namespace std;
#define PI 3.14
#define SQUARE(x) (x * x) // macro

int main()
{
    // int r;

    // cin >> r;
    // cout << PI * r * r << endl;

    int x = 36 / SQUARE(6);

    cout << x;

    return 0;
}