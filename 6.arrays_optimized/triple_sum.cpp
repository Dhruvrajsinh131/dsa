#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int countTriplets(vector<int> &arr, int n, int target)
{
    sort(arr.begin(), arr.end()); // Sort the array
    int count = 0;

    // Iterate through the array
    for (int i = 0; i < n - 2; ++i)
    {
        int left = i + 1, right = n - 1;

        // Two-pointer approach
        while (left < right)
        {
            int currentSum = arr[i] + arr[left] + arr[right];

            if (currentSum == target)
            {
                count++;

                // Move both pointers to look for other triplets
                left++;
                right--;
            }
            else if (currentSum < target)
            {
                left++; // Increase the sum
            }
            else
            {
                right--; // Decrease the sum
            }
        }
    }
    return count;
}

int main()
{

    vector<int> arr = {2, -5, 8, -6, 0, 5, 10, 11, -3};
    int target = 10;

    cout << countTriplets(arr, arr.size(), target) << endl;

    return 0;
}
