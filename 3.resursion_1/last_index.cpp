#include <iostream>
using namespace std;

int getLastIndex(int *arr, int size, int target, int index)
{
    if (size == 0)
    {
        return -1;
    }

    int lastIndex = getLastIndex(arr + 1, size - 1, target, index + 1);

    if (lastIndex != -1)
    {
        return lastIndex;
    }

    if (*arr == target)
    {
        return index;
    }
    return -1;
}

int main()
{
    int arr[] = {123, 4575, 4, 234, 456, 4, 234, 4, 2352324, 235, 235};
    int size = 11;
    int target = 235;

    cout << getLastIndex(arr, size, target, 0);
}