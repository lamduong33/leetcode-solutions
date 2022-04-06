#include <unordered_map>
#include <vector>
using std::vector;

class Solution
{
public:
    int maxArea(vector<int>& height)
    {
        auto best = std::min(height[0], height[1]); // first interval
        if (height.size() == 2)
            return best; // edge case is just first interval
        int p1 = 0, p2 = 2;
        std::unordered_map<int, int> bestRange{};

        while (p1 != (int)height.size())
        {
            if (p2 != height.size())
            {
                auto area1 = std::min(height[p1], height[p2]) * (p2 - p1);
                auto area2 =
                    std::min(height[p1 + 1], height[p2]) * (p2 - (p1 + 1));
                auto better = std::max(area1, area2);
                if (area1 <= area2)
                    p1++;
                if (better > best)
                    best = better;
                p2++;
            }
            else if (p1 != height.size())
            {
                p2 = height.size()-1;
                auto area = std::min(height[p1], height[p2]) * ((p2) - p1);
                if (area > best)
                {
                    best = area;
                }
                p2 = height.size();
                p1++;
            }
        }

        return best;
    }
};
