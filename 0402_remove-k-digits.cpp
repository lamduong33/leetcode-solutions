#include <string>

using std::string;

class Solution
{
public:
    string removeKdigits(string num, int k)
    {
        std::string result = "";

        int comp = num.size() - k;
        auto lastSmallest = 0;

        for (int i = 0; i < comp; i++)
        {
            auto smallest = num[lastSmallest];
            auto jStart = lastSmallest;
            for (int j = jStart; j < i + k + 1; j++)
            {
                if (num[j] < smallest)
                {
                    lastSmallest = j + 1; // lastSmallest is now the next one.
                    smallest = num[j];
                }
            }
            lastSmallest =
                (jStart + 1 >= lastSmallest) ? jStart + 1 : lastSmallest;
            result.push_back(smallest);
            result.erase(0, result.find_first_not_of('0'));
        }
        result = result == "" ? "0" : result; // for 0 edge case.
        return result;
    }
};
