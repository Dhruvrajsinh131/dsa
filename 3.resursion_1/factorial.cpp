#include <iostream>
using namespace std;

int factorial(int n)
{

    if (n == 0)
    {
        return 1;
    }

    int result = factorial(n - 1);
    int output = n * result;

    return output;
}

int main()
{
    int num;
    cout << "Enter the number : ";
    cin >> num;

    int ans = factorial(6);

    cout << "Answer = " << ans;
}