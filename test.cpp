#include <iostream>
#include <vector>
using namespace std;

void backtrack(int index, vector<int> &nums, vector<int> &currSubset, vector<vector<int>> &output, int sum, int k)
{

    if (index == nums.size())
    {
        if (sum == k)
        {

            output.push_back(currSubset);
        }
        return;
    }
    backtrack(index + 1, nums, currSubset, output, sum, k);

    currSubset.push_back(nums[index]);
    backtrack(index + 1, nums, currSubset, output, sum + nums[index], k);
    currSubset.pop_back();
}

vector<vector<int>> getSubsets(vector<int> &nums)
{
    vector<vector<int>> output;
    vector<int> currSubset;
    int sum = 0;
    int k = 4;

    backtrack(0, nums, currSubset, output, sum, k);
    return output;
}

int main()
{
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> output = getSubsets(nums);

    for (int i = 0; i < output.size(); i++)
    {
        for (int j = 0; j < output[i].size(); j++)
        {
            cout << output[i][j] << " ";
        }
        cout << endl;
    }
}