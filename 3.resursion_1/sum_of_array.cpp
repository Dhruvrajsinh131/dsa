#include <iostream>

using namespace std;

int getSumOfArray(int *arr, int size)
{
    if (size == 0)
    {
        return 0;
    }

    return *arr + getSumOfArray(arr + 1, size - 1);
}

int main()
{
    int arr[] = {1, 1, 1, 1, 1};
    int size = 5;

    int total_sum = getSumOfArray(arr, size);

    cout << "Total sum = " << total_sum;
}