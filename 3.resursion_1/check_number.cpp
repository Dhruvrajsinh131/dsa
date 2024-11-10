#include <iostream>
using namespace std;

bool findNumber(int *arr, int size, int target)
{
    if (size == 0)
    {
        return false;
    }

    if (*arr == target)
        return true;

    return findNumber(arr + 1, size - 1, target);
}

int main()
{
    int arr[] = {2, 4, 6, 8, 11, 12};
    int size = 6;

    cout << findNumber(arr, size, 344);
}