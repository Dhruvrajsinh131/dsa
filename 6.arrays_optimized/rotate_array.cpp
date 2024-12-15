#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void reverseArray(vector<int> &arr, int start, int end)
{
    while (start < end)
    {
        swap(arr[start], arr[end]);
        start++;
        end--;
    }
}

void rotateArray(vector<int> &arr, int k)
{
    int n = arr.size();
    if (n == 0)
        return;

    k = k % n;

    reverseArray(arr, 0, k - 1);
    reverseArray(arr, k, n - 1);
    reverseArray(arr, 0, n - 1);
}

void printArray(const vector<int> &arr)
{
    for (int num : arr)
    {
        cout << num << " ";
    }
    cout << endl;
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7};
    int k = 3;
    cout << "Original Array: ";
    printArray(arr);

    rotateArray(arr, k);

    cout << "Array after rotation: ";
    printArray(arr);

    return 0;
}
