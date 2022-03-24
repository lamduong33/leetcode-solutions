#include <algorithm>
#include <vector>
using std::vector;

class Solution
{
public:
    int coinChange(vector<int>& coins, int amount)
    {
        if (amount == 0) return 0;
        auto result = -1;
        std::sort(coins.begin(), coins.end());

        auto largestCoin = coins[coins.size()-1];
        for (auto i = 0; i < (int)coins.size(); i++)
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
        vector<int>{2,2};
        result = coinChange(coins, amount-largestCoin);
        if (result != -1) result++;
        return result;
    }
};
