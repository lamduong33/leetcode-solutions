#include <string>
#include <unordered_map>

class Solution
{
    std::unordered_map<char, int> symbols{{'I', 1},   {'V', 5},   {'X', 10},
                                          {'L', 50},  {'C', 100}, {'D', 500},
                                          {'M', 1000}};
public:
    int romanToInt(std::string s)
    {
        int result = 0;
        for (int i = 0; i < (int)s.length(); i++)
        {
            int value = symbols[s[i]];
            if (i != (int)s.length() - 1)
                if (symbols[s[i]] < symbols[s[i + 1]])
                    value *= -1;
            result += value;
        }
        return result;
    }
};
