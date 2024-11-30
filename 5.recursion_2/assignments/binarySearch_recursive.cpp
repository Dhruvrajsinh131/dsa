#include <iostream>
using namespace std;

int bs(int *arr, int start, int end, int targetElement)
{
    if (start > end)
    {
        return -1;
    }

    int mid = start + (end - start) / 2;

    if (arr[mid] == targetElement)
        return mid;

    else if (arr[mid] > targetElement)
    {
        return bs(arr, start, mid - 1, targetElement);
    }
    else
    {
        return bs(arr, mid + 1, end, targetElement);
    }
}

int main()
{
    int arr[] = {2, 4, 5, 7, 9, 12, 14, 24, 35};
    int length = 9;
    int targetElement = 5;

    cout << bs(arr, 0, length - 1, targetElement);
}