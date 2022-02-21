#include <algorithm>
#include <vector>
using std::vector;

class Solution
{
public:
    int majorityElement(vector<int>& nums)
    {
        int size = nums.size();
        std::sort(nums.begin(), nums.end());
        auto countNum = nums[0];
        auto count = 0;

        for (auto num : nums)
        {
            if (num != countNum)
            {
                countNum = num;
                count = 0;
            }
            count++;
            if (count > (nums.size()/2))
                break;
        }
        return countNum;
    }
};
