#include <unordered_map>
#include <vector>
#include <utility>
#include <functional>
#include <iostream>
#include <unistd.h>

// The name of the solution function is "twoSum"
class Solution
{
public:
    // Hashmap solution. O(N)
    std::vector<int> twoSum(const std::vector<int> &nums, const int target)
    {
        std::vector<int> result;

        // Create a hashmap for O(N). While inserting, check to see if
        // the complement is already in the map.
        std::unordered_map<int, int> hashNums;
        for (int i = 0; i < nums.size(); i++)
        {
            int complement = target - nums[i];
            auto complementTarget = hashNums.find(complement);
            if (complementTarget != hashNums.end())  // If the complement is in the hashmap
            {
                result.push_back(complementTarget->second);
                result.push_back(i);
                break;
            }
            hashNums.insert(std::make_pair(nums[i], i));
        }
        return result;
    }
};
