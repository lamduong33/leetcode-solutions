#include <cmath>
#include <iostream>
#include <vector>
using std::vector;

class Solution
{
public:
    int minimumDeviation(vector<int>& nums)
    {
        auto smallestEven = 0, largestOdd = 0, min = 0, max = 0;

        do
        {
            for (int i = 0; i < nums.size(); i++)
            {
                if (nums[i] < min || min == 0)
                    min = nums[i];
                if (nums[i] > max)
                    max = nums[i];
                if (nums[i] % 2 == 0)
                {
                    if (nums[i] < smallestEven || smallestEven == 0)
                        smallestEven = nums[i];
                    if (nums[i] / 2 > smallestEven)
                        nums[i] /= 2;
                }
                else
                {
                    if (nums[i] > largestOdd || largestOdd == 0)
                        largestOdd = nums[i];
                    if (nums[i] / 2 < largestOdd)
                        nums[i] *= 2;
                }
            }
            std::cout << std::endl << "min: " << min << " max: " << max;
            std::cout << " SE: " << smallestEven << " LO: " << largestOdd
                      << std::endl;
            ;
        }
        while (smallestEven != min && largestOdd != max);
        for (auto e : nums)
            std::cout << e << ",";
        auto result = abs(largestOdd - smallestEven);
        return result;
    }
};
