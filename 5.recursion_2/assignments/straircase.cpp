#include <iostream>
using namespace std;

int straircase(int num)
{

    if (num < 0)
    {
        return 0;
    }
    if (num == 0)
    {
        return 1;
    }

    return straircase(num - 1) + straircase(num - 2) + straircase(num - 3);
}

int main()
{
    int num;
    cout << "Enter the number : ";
    cin >> num;

    int ways = straircase(num);

    cout << "Answer = " << ways;
}