#include <iostream>
#include <string>
#include <vector>
using std::string;
using std::vector;

class Solution
{
    std::string constructRange(int num1, int num2)
    {
        auto result = std::to_string(num1);
        if (num1 == num2)
            return result;
        else
            return result + "->" + std::to_string(num2);
    }
public:
    vector<string> summaryRanges(vector<int>& nums)
    {
        vector<string> result{};
        auto ptr1 = 0, ptr2 = 0;
        string  range = "";
        while (ptr2 != (int)nums.size())
        {
            range = constructRange(nums[ptr1], nums[ptr2]);
            if (ptr2 == (int)nums.size()-1)
            {
                // last one
                result.push_back(range);
            }
            else if (nums[ptr2+1] > nums[ptr2]+1)
            {
                result.push_back(range);
                ptr1 = ptr2+1;
            }
            ptr2++;
        }
        return result;
    }
};
