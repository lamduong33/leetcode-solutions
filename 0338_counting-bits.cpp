#include <vector>
#include <cmath>
using std::vector;

class Solution {
public:
    vector<int> countBits(int n)
    {
        vector<int> result;
        int p = 0;  // power of two
        for (int i = 0; i <= n; i++)
        {
            if (i == 0)
                result.push_back(0);
            else
            {
                auto power = pow(2, p);
                auto prevPower = pow(2, p-1);
                if (i == power)
                {
                    result.push_back(1); // every 2^p will always have one 1
                }
                else if (i < power + prevPower)
                {
                    result.push_back(result[(i-power)+prevPower]);
                }
                else
                {
                    result.push_back(result[(i-prevPower)]+1);
                }
                if (i == pow(2, p+1)-1)
                {
                    p++;
                }
            }
        }
        return result;
    }
};
