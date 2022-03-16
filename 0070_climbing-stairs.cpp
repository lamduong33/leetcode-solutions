class Solution
{
public:
    int climbStairs(int n)
    {
        auto result = 1;
        auto previous = 0;
        for (int i = 1; i <= n; i++)
        {
            auto temp = result;
            result += previous;
            previous = temp;
        }
        return result;
    }
};
