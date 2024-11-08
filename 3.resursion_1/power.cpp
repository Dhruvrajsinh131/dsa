#include <iostream>
using namespace std;

int getPower(int n, int p)
{
    if (p == 0)
    {
        return 1;
    }

    int val = getPower(n, p - 1);

    return n * val;
}

int main()
{
    int num, power;

    cout << "Enter the number : ";
    cin >> num;

    cout << "Enter power : ";
    cin >> power;

    int ans = getPower(num, power);

    cout << "Answer = " << ans;
}