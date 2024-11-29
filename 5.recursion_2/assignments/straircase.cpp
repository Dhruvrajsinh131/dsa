#include <iostream>
using namespace std;

int staircase(int num)
{

    if (num < 0)
    {

        return 0;
    }

    if (num == 0)
    {

        return 1;
    }

    return staircase(num - 1) + staircase(num - 2) + staircase(num - 3);
}

int main()
{

    int num;

    cout << "Enter the number of staircases : ";
    cin >> num;

    cout << "Numnber of possible ways = " << staircase(num);
}