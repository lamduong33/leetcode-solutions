#include <vector>

class Solution
{
public:
    // Given an array of integers nums and an integer k, return the total
    // number of continuous subarrays whose sum equals to k.
    int subarraySum(std::vector<int>& nums, int k)
    {
        auto result = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            auto rollingSum = 0;
            for (int j = i; j < nums.size(); j++)
            {
                rollingSum += nums[j];
                if (rollingSum == k)
                {
                    result++;
                }
            }
        }
        return result;
    }
};
