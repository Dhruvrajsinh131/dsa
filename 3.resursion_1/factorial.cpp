#include <iostream>
using namespace std;

int factiorial(int n)
{
    if (n == 0)
    {
        return 1;
    }
    int val = factiorial(n - 1);
    return n * val;
}

int main()
{
    int num;

    cout << "Enter the number : ";
    cin >> num;

    int answer = factiorial(5);

    cout << "Answer = " << answer;
}