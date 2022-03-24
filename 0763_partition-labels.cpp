#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

class Solution
{
public:
    std::vector<int> partitionLabels(std::string s)
    {
        std::vector<int> result{};

        std::unordered_map<char, int> charStart; // keep track where each char start
        std::vector<std::pair<int, int>> rangeMap; // the ranges for each map

        // Get ranges of characters
        for (int i = 0; i < s.size(); i++)
        {
            if (charStart.count(s.at(i)))
            {

            }
            else
            {

            }
        }

        // Get blocks of overlapping ranges
        for (auto range : rangeMap)
        {
        }

        // Get the size of each block and insert in result
        return result;
    }
};
