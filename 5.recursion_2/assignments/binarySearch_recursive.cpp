#include <iostream>
using namespace std;

int bs(int *arr, int start, int end, int target)
{
    if (start > end)
    {
        return -1;
    }

    int mid = start + (end - start) / 2;

    if (arr[mid] == target)
        return mid;

    else if (arr[mid] > target)
    {
        return bs(arr, start, mid - 1, target);
    }
    else
    {
        return bs(arr, mid + 1, end, target);
    }
}

int main()
{
    int arr[] = {2, 4, 5, 7, 9, 12, 14, 24, 35};
    int length = 9;
    int target = 5;

    cout << bs(arr, 0, length - 1, target);
}