#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

class Solution
{
public:
    /* Revised solution */
    std::vector<std::vector<int>> threeSum(std::vector<int> &nums)
    {
        auto result = std::vector<std::vector<int>>(); // the result as a vector
        std::sort(nums.begin(), nums.end());
        for (int i = 0; i < (int)nums.size() - 2; i++)
        {
            if ((i != 0) && (nums[i] == nums[i - 1]))
            {
                continue; // avoid duplicate
            }
            int j = i + 1;
            int k = (int)nums.size() - 1;
            while (j < k)
            {
                int sum = nums[i] + nums[j] + nums[k];
                if (sum == 0)
                {
                    result.push_back(
                        std::vector<int>{nums[i], nums[j], nums[k]});
                    while (k - 1 > j && nums[k - 1] == nums[k])
                        k--;
                    while (j + 1 > k && nums[j + 1] == nums[j])
                        j++;
                    j++;
                    k--;
                }
                else if (sum < 0)
                    j++;
                else
                    k--;
            }
        }
        return result;
    }
};

