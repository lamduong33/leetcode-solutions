#include <vector>
#include <iostream>
using std::vector;

class Solution
{
public:
    /* An integer array is called arithmetic if it consists of at least three
     * elements and if the difference between any two consecutive elements is
     * the same.
     * Given an integer array nums, return the number of arithmetic subarrays
     * of nums.
     * */
    int numberOfArithmeticSlices(vector<int>& nums)
    {
        int result = 0, difference = 0, count = 0;

        if (nums.size() >= 3)
        {
            for (int i = 1; i < nums.size(); i++)
            {
                auto diff = nums[i] - nums[i - 1];
                if (count == 0 || diff != difference)
                {
                    difference = diff;
                    count = 1;
                }
                else
                {
                    count++;
                }
                result += count-1;
            }
        }

        return result;
    }
};
