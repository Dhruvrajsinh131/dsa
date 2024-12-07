// SubSets

#include <iostream>
#include <vector>
using namespace std;

int getSubsets(vector<int> &input, int ipSize, int index, vector<vector<int>> &output)
{

    if (ipSize == index)
    {
        output.push_back({});
        return 1;
    }

    int smallArrayLength = getSubsets(input, ipSize, index + 1, output);

    for (int i = 0; i < smallArrayLength; i++)
    {
        vector<int> newArray = output[i];
        newArray.insert(newArray.begin(), input[index]);
        output.push_back(newArray);
    }
    return 2 * smallArrayLength;
}

int main()
{
    vector<int> input = {2, 3};

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