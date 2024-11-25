#include <iostream>
using namespace std;

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

// int partition(int arr[], int low, int high)
// {
//     int pivot = arr[high];
//     int i = low - 1;

//     for (int j = low; j <= high - 1; j++)
//     {
//         if (arr[j] < pivot)
//         {
//             i++;
//             swap(arr[i], arr[j]);
//         }
//     }
//     swap(arr[i + 1], arr[high]);
//     return i + 1;
// }

// void quickSort(int arr[], int low, int high)
// {
//     if (low < high)
//     {
//         int pi = partition(arr, low, high);

//         quickSort(arr, low, pi - 1);
//         quickSort(arr, pi + 1, high);
//     }
// }

void quickSort(int *arr, int left, int right)
{
    if (left >= right)
    {
        return;
    }
    int l = left;
    int r = right;
    int mid = left + (right - left) / 2;
    int pivot = arr[mid];

    while (l <= r)
    {
        while (arr[l] < pivot)
        {
            l++;
        }
        while (arr[r] > pivot)
        {
            r--;
        }

        if (l <= r)
        {
            swap(arr[l], arr[r]);
            l++;
            r--;
        }
    }
    if (left < r)
        quickSort(arr, left, r);
    if (l < right)
        quickSort(arr, l, right);
}

int main()
{
    int arr[] = {10, 7, 8, 9, 1, 5, 5};
    int n = 7;

    cout << "Original array: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    quickSort(arr, 0, n - 1);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
