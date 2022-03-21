#include <vector>
using std::vector;

class Solution
{
public:

    int coinChange(vector<int>& coins, int amount)
    {
        if (amount == 0) return 0;
        auto result = -1;
        auto largestCoin = coins[coins.size()-1];
        for (auto i = 0; i < coins.size(); i++)
        {
            if (amount == coins[i])
                return 1;
            else if (amount < coins[i])
            {
                if (i == 0)
                {
                    return result;
                }
                largestCoin = coins[i-1];
                break;
            }
        }
        result = coinChange(coins, amount-largestCoin)+1;
        return result;
    }
};
