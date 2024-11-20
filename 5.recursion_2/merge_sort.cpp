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

void printArr(int *arr, int size)
{

    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int arr[] = {4, 2, 6, 8, 1};
    int size = 5;
    cout << "Before Sort : ";
    printArr(arr, size);

    mergeSort(arr, 0, size - 1);

    cout << "After sort : ";
    printArr(arr, size);
}