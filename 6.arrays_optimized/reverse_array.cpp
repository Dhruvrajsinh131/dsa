#include <iostream>
#include <vector>
#include <algorithm> // For std::reverse

using namespace std;

// Function to reverse a portion of the array
void reverseArray(vector<int> &arr, int start, int end)
{
    while (start < end)
    {
        swap(arr[start], arr[end]);
        start++;
        end--;
    }
}

// Function to rotate the array by a given index
void rotateArray(vector<int> &arr, int k)
{
    int n = arr.size();
    if (n == 0)
        return;

    // Handle cases where k > n
    k = k % n;

    // Reverse the three sections
    reverseArray(arr, 0, k - 1); // Reverse the first part
    reverseArray(arr, k, n - 1); // Reverse the second part
    reverseArray(arr, 0, n - 1); // Reverse the entire array
}

// Helper function to print the array
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
    int k = 3; // Index to rotate the array

    cout << "Original Array: ";
    printArray(arr);

    rotateArray(arr, k);

    cout << "Array after rotation: ";
    printArray(arr);

    return 0;
}
