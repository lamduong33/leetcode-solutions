#include <cmath>
#include <iostream>
#include <vector>
using std::vector;

class Solution
{
    void checkExtremes(int* SE, int* LO, int* min, int* max, vector<int>& nums)
    {
        *SE = 0, *LO = 0, *min = 0, *max = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] < *min || *min == 0)
                *min = nums[i];
            if (nums[i] > *max)
                *max = nums[i];
            if ((nums[i] % 2 == 0) && (nums[i] < *SE) || (*SE == 0))
                *SE = nums[i];
            if ((nums[i] % 2 != 0) && (nums[i] > *LO) || (*LO == 0))
                *LO = nums[i];
        }
    }

public:
    int minimumDeviation(vector<int>& nums)
    {
        auto smallestEven = 0, largestOdd = 0, min = 0, max = 0;
        checkExtremes(&smallestEven, &largestOdd, &min, &max, nums);
        while (smallestEven != min || largestOdd != max)
        {
            for (int i = 0; i < nums.size(); i++)
            {
                if ((nums[i] % 2 == 0) && (nums[i] / 2 > smallestEven))
                {
                    nums[i] /= 2;
                }
                else if ((nums[i] % 2 != 0) && (nums[i] * 2 < largestOdd))
                {
                    nums[i] *= 2;
                }
            }
            checkExtremes(&smallestEven, &largestOdd, &min, &max, nums);
        }

        auto result = abs(largestOdd - smallestEven);

        return result;
    }
};
