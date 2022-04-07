#include <algorithm>
#include <vector>
using std::vector;

class Solution
{
public:
    int coinChange(vector<int>& coins, int amount)
    {
        int count = 0;
        std::sort(coins.begin(), coins.end(), std::greater<int>());
        for (auto coin : coins)
        {
            while (coin < amount)
            {
                amount -= coin;
                count++;
            }
        }
        return count+1;
    }
};
