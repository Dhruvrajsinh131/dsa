#include <iostream>
using namespace std;

double getGeomatricSum(int num)
{
    if (num == 0)
    {
        return 1;
    }

    double power = 1.0;
    for (int i = 0; i < num; i++)
    {
        power *= 2;
    }

    return 1.0 / power + getGeomatricSum(num - 1);
}

int main()
{

    int num;
    cout << "Enter the number : ";
    cin >> num;

    double ans = getGeomatricSum(num);

    cout << "Answer = " << ans;
}