#include <vector>
#include <algorithm>
using std::vector;

class Solution
{
public:
    /**
     * O(n log n) runtime and O(1) space. Make sure to include <algorithm>*/
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
