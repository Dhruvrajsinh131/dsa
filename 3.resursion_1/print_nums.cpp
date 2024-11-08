#include <iostream>
using namespace std;

void print_nums(int c, int n)
{
    if (c > n)
    {
        return;
    }
    cout << c << " ";

    print_nums(c + 1, n);
}

int main()
{

    int num;

    cout << "Enter the number : ";
    cin >> num;

    print_nums(1, num);
}