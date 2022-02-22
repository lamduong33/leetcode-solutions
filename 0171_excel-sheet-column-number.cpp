class Solution
{
public:
    int titleToNumber(string columnTitle)
    {
        int value = 0, n = columnTitle.size();

        for (int i = 0; i < n; i++)
        {
            auto compVal = columnTitle[n-i-1]-64;
            value += (int)pow(26, n-(n-i)) * compVal;
        }

        return value;
    }
};
