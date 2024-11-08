#include <iostream>
using namespace std;
int getNumOfDigits(int n)
{
    if (n == 0)
    {
        return 0;
    }

    int val = getNumOfDigits(n / 10);
    return 1 + val;
}

int main()
{
    int num;
    cout << "Enter the number : ";
    cin >> num;

    int ans = getNumOfDigits(num);

    cout << "Answer = " << ans;
}