#include <iostream>
using namespace std;

void merge(int *arr, int start, int mid, int end)
{

    int n1 = mid + 1 - start;
    int n2 = end - mid;

    int leftArr[n1], rightArr[n2];

    for (int i = 0; i < n1; i++)
    {
        leftArr[i] = arr[start + i];
    }

    for (int i = 0; i < n2; i++)
    {
        rightArr[i] = arr[mid + 1 + i];
    }

    int i = 0, j = 0, k = start;

    while (i < n1 && j < n2)
    {
        if (leftArr[i] <= rightArr[j])
        {
            arr[k] = leftArr[i];
            i++;
        }
        else
        {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = leftArr[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = rightArr[j];
        j++;
        k++;
    }
}

void mergeSort(int *arr, int start, int end)
{
    if (start >= end)
    {
        return;
    }

    int mid = start + (end - start) / 2;

    mergeSort(arr, start, mid);
    mergeSort(arr, mid + 1, end);

    merge(arr, start, mid, end);
}

int main()
{
    int arr[] = {1, 2, 5, 6, 73, 3, 4, 8};
    int length = 8;

    //=================> Brute Force

    // for (int i = 0; i < length; i++)
    // {
    //     for (int j = i + 1; j < length; i++)
    //     {
    //         if (arr[i] == arr[j])
    //         {
    //             cout << "Duplicate Element Found : " << arr[j];
    //         }
    //     }
    // }

    //========> using Sort
    mergeSort(arr, 0, length - 1);

    for (int i = 0; i < length; i++)
    {

        if (arr[i] == arr[i + 1])
        {
            cout << "Duplicate element found : " << arr[i];
            return 0;
        }
    }

    cout << "No Duplicates Found";
}