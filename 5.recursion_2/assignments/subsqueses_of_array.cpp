#include <iostream>
using namespace std;

int generateSubsets(int nums[], int length, int index, int output[][20])
{

    if (length == index)
    {
        output[0][0] = 0;
        return 1;
    }

    int smallOutputLength = generateSubsets(nums, length, index + 1, output);

    for (int i = 0; i < smallOutputLength; i++)
    {
        int currentSubSetLength = output[i][0];

        output[i + smallOutputLength][0] = currentSubSetLength + 1;
        output[i + smallOutputLength][1] = nums[index];

        for (int j = 1; j <= currentSubSetLength; j++)
        {
            output[i + smallOutputLength][j + 1] = output[i][j];
        }
    }

    return 2 * smallOutputLength;
}

int main()
{
    int nums[] = {1, 2, 3};
    int n = 3;

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
