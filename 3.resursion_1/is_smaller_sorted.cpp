#include <iostream>
using namespace std;

bool isSorted2(int *arr, int size)
{
    if (size == 0 || size == 1)
    {
        return true;
    }
    bool isSmallerSorted = isSorted2(arr + 1, size - 1);

    if (!isSmallerSorted)
    {
        return false;
    }

    if (*arr > *(arr + 1))
    {
        return false;
    }
    {
        return true;
    }
}

bool isSorted(int *arr, int size)
{
    if (size == 0 || size == 1)
    {
        return true;
    }
    if (*arr > *(arr + 1))
    {
        return false;
    }

    bool isSmallerSorted = isSorted(arr + 1, size - 1);
    return isSmallerSorted;
}

int main()
{

    int arr1[] = {2, 4, 6, 8, 9};
    int siz1 = 5;
    int arr2[] = {2, 4, 6, 8, 3, 4};
    int siz2 = 6;

    cout << "arr1 is sorted = " << isSorted2(arr1, siz1) << endl;
    cout << "arr2 is sorted = " << isSorted2(arr2, siz2) << endl;
}