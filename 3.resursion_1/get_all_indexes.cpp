#include <iostream>
using namespace std;

void getAllindex(int *arr, int size, int target, int index, int result[], int &count)
{
    if (size == 0)
        return;

    if (*arr == target)
    {
        result[count++] = index;
    }

    getAllindex(arr + 1, size - 1, target, index + 1, result, count);
}

int main()
{
    int arr[] = {123, 4575, 4, 234, 456, 4, 234, 4, 2352324, 235, 235};
    int size = 11;
    int target = 4;
    int result[100];
    int count = 0;

    getAllindex(arr, size, target, 0, result, count);

    for (int i = 0; i < count; i++)
    {
        cout << result[i] << " ";
    }
}