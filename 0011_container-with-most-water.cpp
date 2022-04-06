#include <vector>
using std::vector;

class Solution
{
public:
    int maxArea(vector<int>& height)
    {
        int best = 0, i = 0, j = (int)height.size()-1;
        if (height.size() == 2) return std::min(height[0], height[1]);
        while (i < j)
        {
            auto area = std::min(height[i], height[j]) * (j-i);
            //std::cout << "area: " << area << std::endl;
            if (area > best)
                best = area;
            if ((height[j] - height[i+1]) > (height[j-1] - height[i]))
                j--;
            else
                i++;
        }
        return best;
    }
};
