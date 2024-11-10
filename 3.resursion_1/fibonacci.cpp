#include <iostream>
using namespace std;
int getFib(int n)
{
    if (n == 0)
    {
        return 0;
    }
    if (n == 1)
    {
        return 1;
    }

    int temp1 = getFib(n - 1);
    int temp2 = getFib(n - 2);
    return temp1 + temp2;
}

int main()
{

    int num;
    cout << "Enter the number : ";
    cin >> num;

    cout << "Answer = " << getFib(num);
}