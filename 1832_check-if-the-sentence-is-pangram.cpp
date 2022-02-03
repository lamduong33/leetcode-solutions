#include <string>
#include <vector>
#include <unordered_set>

class Solution
{
public:
    std::vector<char> alphabet = {
        'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm',
        'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    bool checkIfPangram(std::string sentence)
    {
        auto sentenceSet = turnToSet(sentence);
        for (auto &character : alphabet)
        {
            if (!sentenceSet.count(character))
            {
                return false;
            }
        }
        return true;
    }

    /* Helper function that turns a string to an unordered_set */
    std::unordered_set<char> turnToSet(std::string sentence)
    {
        std::unordered_set<char> result;
        for (auto &c : sentence)
        {
            result.insert(c);
        }
        return result;
    }
};
