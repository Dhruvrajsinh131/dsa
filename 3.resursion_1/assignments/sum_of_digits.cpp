#include <iostream>
using namespace std;

int getSum(int num)
{
    if (num == 0)
    {
        return 0;
    }

    int tempNum = num % 10;

    return tempNum + getSum(num / 10);
}

int main()
{
    int num;

    cout << "Enter the number : ";
    cin >> num;

    int ans = getSum(num);

    cout << "Answer = " << ans;
}