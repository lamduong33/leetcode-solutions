// #include <vector>
// using std::vector;

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
            if (area > best)
                best = area;
            if (height[i] < height[j])
                i++;
            else
                j--;
        }
        return best;
    }
};

// [2,3,4,5,18,17,6]
// [1,3,2,5,25,24,5]
