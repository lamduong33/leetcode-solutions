#include <string>
#include <unordered_map>

class Solution
{
public:
    /**
     * Given two strings s1 and s2, return true if s2 contains a permutation of
     * s1, or false otherwise. In other words, return true if one of s1's
     * permutations is the substring of s2.
     * */
    bool checkInclusion(std::string s1, std::string s2)
    {
        bool result = false;
        int matchSize = (int)s1.size(), matchCount = 0;

        // Build targets, for matches after => O(s1)
        std::unordered_map<char, int> targets, encountered;
        for (auto character : s1)
        {
            if (targets.count(character))
            {
                targets[character]++;
            }
            else
            {
                targets[character] = 1;
            }
        }

        // Check for matches => O(s2)
        for (auto character : s2)
        {
            if (targets.count(character))
            {
                if (encountered.count(character))
                    encountered[character]++;
                else
                    encountered[character] = 1;

                if (encountered[character] == targets[character])
                {
                    matchCount++;
                    if (matchCount == matchSize)
                    {
                        result = true;
                        break;
                    }
                }
                else if (encountered[character] > targets[character])
                {
                    // TODO: Restart
                }
            }
            else
            {
                // TODO: Restart
            }
        }

        // Final runtime => O(s1+s2)
        return result;
    }
};
