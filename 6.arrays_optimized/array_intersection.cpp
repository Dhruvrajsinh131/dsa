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

        k++;
        i++;
    }
    while (j < n2)
    {
        arr[k] = rightArr[j];

        k++;
        j++;
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
    int arr1[] = {12, 4, 5, 4, 6};
    int length1 = 5;
    int arr2[] = {12, 4, 5, 2, 6, 1};
    int length2 = 6;

    mergeSort(arr1, 0, length1 - 1);
    mergeSort(arr2, 0, length2 - 1);

    int i = 0, j = 0;

    while (i < length1 && j < length2)
    {
        if (arr1[i] < arr2[j])
        {
            i++;
        }
        else if (arr1[i] > arr2[j])
        {
            j++;
        }
        else
        {
            cout << arr1[i] << " ";
            i++;
            j++;
        }
    }
}