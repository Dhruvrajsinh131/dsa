#include <iostream>
using namespace std;

inline int max(int a, int b) // Inline function
{

    return (a > b) ? a : b;
}

int sum(int *arr, int size, int start = 0)
{
    int sum = 0;

    for (int i = start; i < size; i++)
    {
        sum += arr[i];
    }
    return sum;
}

int sum2(int a, int b = 0, int c = 0, int d = 0)
{

    return a + b + c + d;
}

int main()
{
    int a = 23, b = 45;

    int c = max(a, b);

    cout << "max = " << c << endl;
    int x = 546, y = 87;

    int z = max(x, y);
    cout << "max = " << z << endl;

    int arr[] = {1, 2, 3};
    int size = 3;

    cout << sum(arr, 3, 1) << endl;

    cout << sum2(1) << endl;
    cout << sum2(1, 2) << endl;
    cout << sum2(1, 2, 3) << endl;
    cout << sum2(1, 2, 3, 4) << endl;
}
