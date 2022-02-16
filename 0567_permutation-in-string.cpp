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

        // Build targets, for matches after => O(s1)
        std::unordered_map<char, int> targets, encountered;
        for (auto character : s1)
            targets[character]++;
        int matchSize = (int)targets.size(), matchCount = 0, p1 = 0;

        for (int p2 = 0; p2 < s2.size(); p2++)
        {
            if (targets.count(s2[p2]))
            {
                // Check if sliding window size is exceeded
                if ((p2 - p1) > (s1.size() - 1))
                {
                    if (encountered[s2[p1]] == targets[s2[p1]])
                        matchCount--; // about to lose count, misses target
                    else if (encountered[s2[p1]] == targets[s2[p1]]+1)
                        matchCount++; // lose count reaches target
                    encountered[s2[p1]]--;
                    p1++;
                }
                auto lastChar = s2[p2];
                encountered[lastChar]++;
                if (encountered[lastChar] == targets[lastChar])
                    matchCount++;
                else if (encountered[lastChar] == targets[lastChar]+1)
                    matchCount--;
                if (matchCount == matchSize)
                {
                    result = true;
                    break;
                }
            }
            else
            {
                // reset since this char is not in targets
                encountered.clear();
                matchCount = 0;
                p1 = p2 + 1;
            }
        }

        // Final runtime => O(s1+s2)
        return result;
    }
};
