#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// Function to count the number of pairs that sum to the target
int countPairSums(const vector<int> &nums, int target)
{
    unordered_map<int, int> freq_map; // Map to store frequency of each number
    int count = 0;

    // Iterate through the array
    for (int num : nums)
    {
        int complement = target - num;

        // If the complement exists in the map, it contributes to the pair count

        if (freq_map.find(complement) != freq_map.end())
        {
            count += freq_map[complement];
        }

        // Update the frequency of the current number
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
