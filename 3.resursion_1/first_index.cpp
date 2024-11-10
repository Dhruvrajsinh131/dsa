#include <iostream>
using namespace std;

int getFirstIndex(int *arr, int size, int target, int index)
{
    if (size == 0)
    {
        return -1;
    }

    if (*arr == target)
    {
        return index;
    }
    return getFirstIndex(arr + 1, size - 1, target, index + 1);
}
int main()
{

    int arr[] = {123, 4575, 4, 234, 456, 4};
    int size = 6;
    int target = 4;

    cout << getFirstIndex(arr, size, target, 0);
}