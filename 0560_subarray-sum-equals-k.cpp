#include <unordered_map>
#include <vector>

class Solution
{
public:
    // Given an array of integers nums and an integer k, return the total
    // number of continuous subarrays whose sum equals to k.
    // NOTE: O(n) solution provided by LeetCode. O(n^2) solution did not work.
    int subarraySum(std::vector<int>& nums, int k)
    {
        auto result = 0, collectiveSum = 0;
        std::unordered_map<int, int> sumsMap;
        sumsMap[0] = 1; // initial 0, to account for single occurrences of k

        for (int i = 0; i < nums.size(); i++)
        {
            collectiveSum += nums[i];
            auto sumDifference = collectiveSum - k;
            if (sumsMap.count(sumDifference))
            {
                result += sumsMap[sumDifference];
            }

            if (sumsMap.count(collectiveSum))
            {
                sumsMap[collectiveSum]++;
            }
            else
            {
                sumsMap[collectiveSum] = 1;
            }
        }

        return result;
    }
};
