#include <vector>
using std::vector;

class Solution
{
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k)
    {
        auto m = grid.size();
        auto n = grid[0].size();
        if (k % (m * n) != 0) // handle edge case
        {
            int a = 0, b = 0, i = k % n, j = k / n;
            // [i,j] is where the first element should be swapped to
            while (i < m && j < n)
            {
            }
        }
        return grid;
    }
};
