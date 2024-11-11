#include <iostream>
using namespace std;

int getCountOfZeros(int num, int &count)
{
    if (num == 0)
    {
        return count;
    }
    if (num % 10 == 0)
        count++;

    return getCountOfZeros(num / 10, count);
}

int main()
{
    int num;
    cout << "Enter the number : ";
    cin >> num;

    int count = 0;

    if (num == 0)
    {
        cout << "Answer = 1";
        return 0;
    }

    int ans = getCountOfZeros(num, count);

    cout << "Answer = " << ans;
}