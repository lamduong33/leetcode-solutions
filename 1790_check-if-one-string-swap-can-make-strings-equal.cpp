#include <iostream>
#include <string>
#include <unordered_map>

class Solution
{
public:
    /* You are given two strings s1 and s2 of equal length. A string swap is an
     * operation where you choose two indices in a string (not necessarily
     * different) and swap the characters at these indices.
     * Return true if it is possible to make both strings equal by performing at
     * most one string swap on exactly one of the strings. Otherwise, return
     * false.
     */
    bool areAlmostEqual(std::string s1, std::string s2)
    {
        bool result = true;
        std::unordered_map<char, char> charPairs;
        int mismatchCount = 0;

        for (int i = 0; i < s1.length(); i++)
        {
            if (s1.at(i) != s2.at(i))
            {
                mismatchCount++;
                charPairs[s1.at(i)] = s2.at(i); // insert into map
                if (charPairs.count(s2.at(i))) // if matches
                {
                    if (charPairs[s2.at(i)] == s1.at(i))
                        result = true;
                }
                else
                {
                    result = false;
                }
            }
            if (mismatchCount >= 3)
            {
                result = false;
                break;
            }
        }
        return result;
    }
};
