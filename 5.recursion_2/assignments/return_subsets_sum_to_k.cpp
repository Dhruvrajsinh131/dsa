#include <iostream>
using namespace std;

// Function to print a subset
void printSubset(int subset[], int subsetSize)
{
    for (int i = 0; i < subsetSize; i++)
    {
        cout << subset[i] << " ";
    }
    cout << endl;
}

// Recursive function to find subsets
void findSubsets(int input[], int n, int subset[], int subsetSize, int index, int currentSum, int targetSum)
{
    // Base case: if we reach the end of the array
    if (index == n)
    {
        if (currentSum == targetSum)
        {
            printSubset(subset, subsetSize);
        }
        return;
    }

    // Include the current element in the subset
    subset[subsetSize] = input[index];
    findSubsets(input, n, subset, subsetSize + 1, index + 1, currentSum + input[index], targetSum);

    // Exclude the current element from the subset
    findSubsets(input, n, subset, subsetSize, index + 1, currentSum, targetSum);
}

// Main function
int main()
{
    int n;
    cin >> n;
    int input[n];
    for (int i = 0; i < n; i++)
    {
        cin >> input[i];
    }
    int k;
    cin >> k;

    int subset[n]; // Temporary array to store subsets
    findSubsets(input, n, subset, 0, 0, 0, k);

    return 0;
}
