#include <iostream>
using namespace std;

void printSubsets(int *arr, int length, int index, int *output, int outputIndex)
{
    if (length == index)
    {
        for (int i = 0; i < outputIndex; i++)
        {
            cout << output[i] << " ";
        }
        cout << endl;

        return;
    }

    printSubsets(arr, length, index + 1, output, outputIndex);
    output[outputIndex] = arr[index];

    printSubsets(arr, length, index + 1, output, outputIndex + 1);
}

int main()
{
    int arr[] = {1, 2, 3};
    int length = 3;
    int outputIndex = 0;
    int output[outputIndex];

    printSubsets(arr, length, 0, output, outputIndex);
}