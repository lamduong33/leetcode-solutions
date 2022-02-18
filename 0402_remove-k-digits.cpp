#include <string>

using std::string;

class Solution {
public:
    string removeKdigits(string num, int k)
    {
        std::string result = "";

        int comp = num.size()-k;
        auto lastSmallest = 0;
        bool first0 = true;

        for (int i = 0; i < comp; i++)
        {
            auto smallest = num[lastSmallest];
            auto end = num.size()-comp+i;
            for (int j = lastSmallest; j < end+1; j++)
            {
                if (num[j] < smallest)
                {
                    lastSmallest = j+1; // move to next one
                    smallest = num[j];
                }
            }
            lastSmallest = (i+1 >= lastSmallest) ? i+1 : lastSmallest;
            result.push_back(smallest);
        }
        result = result == "" ? "0" : result; // 0 edge case
        return result;
    }
};
