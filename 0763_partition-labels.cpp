#include <vector>
#include <string>
#include <map>
#include <iostream>
using std::vector;
using std::string;
using std::map;
using std::pair;

class Solution {
public:
    vector<int> partitionLabels(string s)
    {
        vector<int> result{};
        map<char, pair<int, int>> ranges;

        // Get overlapping ranges
        for (int i = 0; i < s.size(); i++)
        {
            auto c = s.at(i);
            if (ranges.count(s.at(i)))
                ranges[c].second = i;
            else
                ranges[c] = pair<int,int>{i,i};
        }

        for (auto range : ranges)
        {

        }
        return result;
    }
};
