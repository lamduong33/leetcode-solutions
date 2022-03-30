#include <vector>

class Solution
{
public:
    bool search(std::vector<int>& nums, int target)
    {
        bool result = false;
        auto fp = nums.begin();
        for (auto sp = nums.begin(); sp != nums.end(); sp++)
        {
            if (*sp == target || *fp == target)
                return true;
            if (fp < nums.begin())
                fp += 2; // Increment fast pointer twice
        }
        return result;
    }
};
