#include <iostream>
#include <string>
#include <unordered_map>
#include <variant>

class Solution
{
public:
    /* Hashed Set solution */
    static int lengthOfLongestSubstring(std::string s)
    {
        int result = 0, startPoint = 0;
        std::unordered_map<char, int> subString;

        for (int endPoint = 0; endPoint < (int)s.size(); endPoint++)
        {
            auto charSearch = subString.find(s[endPoint]);
            if (charSearch != subString.end()) // if found
            {
                startPoint = std::max(startPoint, subString[s[endPoint]]);
            }
            result = std::max(result, endPoint - startPoint + 1);
            subString[s[endPoint]] = endPoint + 1;
            std::cout << std::endl;
        }
        return result;
    }
};

