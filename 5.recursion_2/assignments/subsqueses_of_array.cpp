#include <iostream>
#include <vector>
using namespace std;

int getSubsets(vector<int> &input, int ipsize, int index, vector<vector<int>> &output)
{
    if (ipsize == index)
    {
        output.push_back({});
        return 1;
    }

    int smallLength = getSubsets(input, ipsize, index + 1, output);

    for (int i = 0; i < smallLength; i++)
    {
        vector<int> newSubset = output[i];
        newSubset.insert(newSubset.begin(), input[index]);
        output.push_back(newSubset);
    }

    return 2 * smallLength;
}

int main()
{
    vector<int> input = {1, 2, 3};
    vector<vector<int>> output;

    int size = getSubsets(input, input.size(), 0, output);

    for (int i = 0; i < output.size(); i++)
    {
        for (int j = 0; j < output[i].size(); j++)
        {
            cout << output[i][j] << " ";
        }

        cout << endl;
    }
}
