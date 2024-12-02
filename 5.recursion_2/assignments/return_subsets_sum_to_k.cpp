#include <iostream>
using namespace std;

// Helper function for recursive exploration
void findSubsetsSumToK(int input[], int n, int index, int output[], int outputSize, int currentSum, int K)
{
    // Base case: if we've processed all elements
    if (index == n)
    {
        if (currentSum == K)
        { // If the subset sums to K, print it
            for (int i = 0; i < outputSize; i++)
            {
                cout << output[i] << " ";
            }
            cout << endl;
        }
        return;
    }

    // Exclude the current element
    findSubsetsSumToK(input, n, index + 1, output, outputSize, currentSum, K);

    // Include the current element
    output[outputSize] = input[index]; // Add current element to output
    findSubsetsSumToK(input, n, index + 1, output, outputSize + 1, currentSum + input[index], K);
}

// Wrapper function
void subsetsSumToK(int input[], int n, int K)
{
    int output[n]; // Temporary array to store current subset
    findSubsetsSumToK(input, n, 0, output, 0, 0, K);
}

int main()
{
    int n;
    cin >> n;

    int input[n];
    for (int i = 0; i < n; i++)
    {
        cin >> input[i];
    }

    int K;
    cin >> K;

    subsetsSumToK(input, n, K);
    return 0;
}
