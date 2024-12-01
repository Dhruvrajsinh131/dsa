#include <iostream>
using namespace std;

int generateSubsets(int nums[], int n, int index, int output[][20])
{
    if (index == n)
    {
        output[0][0] = 0;
        return 1;
    }

    int subsetCount = generateSubsets(nums, n, index + 1, output);

    for (int i = 0; i < subsetCount; i++)
    {
        int currentSubsetSize = output[i][0];

        output[i + subsetCount][0] = currentSubsetSize + 1;
        output[i + subsetCount][1] = nums[index];

        for (int j = 1; j <= currentSubsetSize; j++)
        {
            output[i + subsetCount][j + 1] = output[i][j];
        }
    }

    return 2 * subsetCount;
}

int main()
{
    int nums[] = {1, 2, 3};
    int n = sizeof(nums) / sizeof(nums[0]);

    int output[1024][20];
    int subsetCount = generateSubsets(nums, n, 0, output);

    cout << "Subsets are:" << endl;
    for (int i = 0; i < subsetCount; i++)
    {

        for (int j = 1; j <= output[i][0]; j++)
        {
            cout << output[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
