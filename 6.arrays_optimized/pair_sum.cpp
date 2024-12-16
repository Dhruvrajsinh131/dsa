#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int countPairSums(const vector<int> &nums, int target)
{
    unordered_map<int, int> freq_map;
    int count = 0;

    for (int num : nums)
    {
        int complement = target - num;

        if (freq_map.find(complement) != freq_map.end())
        {
            count += freq_map[complement];
        }

        ++freq_map[num];
    }

    return count;
}

int main()
{

    vector<int> nums = {1, 2, 3, 4, 3, 1};

    int target = 6;

    // Find and output the count of pairs
    cout << "Answer : " << countPairSums(nums, target) << endl;

    return 0;
}
