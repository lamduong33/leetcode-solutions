#include <string>
#include <unordered_map>

class Solution
{
public:
    int romanToInt(std::string s)
    {
        auto symbols = std::unordered_map<char, int>();
        symbols['I'] = 1;
        symbols['V'] = 5;
        symbols['X'] = 10;
        symbols['L'] = 50;
        symbols['C'] = 100;
        symbols['D'] = 500;
        symbols['M'] = 1000;

        auto rules = std::unordered_map<char, char>();

        int result = 0;

        for (int i = 0; i < s.length(); i++)
        {
            int value = symbols.at(s[i]);

            if (i != s.length() - 1)
                if (symbols.at(s[i]) < symbols.at(s[i+1]))
                    value *= -1;

            result += value;
        }
        return result;
    }
};
