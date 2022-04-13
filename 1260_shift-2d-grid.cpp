#include <iostream>
#include <vector>
using std::vector;

class Solution
{
    void insertGrid(vector<vector<int>>& grid, vector<vector<int>>& result,
                    size_t n, int i, int j)
    {
        if (result.empty() || result.back().size() == n)
            result.push_back(vector<int>{grid[i][j]});
        else
            result.back().push_back(grid[i][j]);
    }

public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k)
    {
        auto m = grid.size();
        auto n = grid[0].size();
        k = k % (m * n); // wrapping k
        vector<vector<int>> result;
        if (k != 0) // handle edge case
        {
            // Insert the last k elements
            int iStart = m - (k / n) - 1, jInit = n - (k % n), jStart = jInit;
            //std::cout << "iStart: " << iStart << ", jStart: " << jStart << std::endl;
            if (jStart == n)
            {
                jStart = 0;
                iStart++;
            }
            for (int i = iStart; i < m; i++)
            {
                for (int j = jStart; j < n; j++)
                {
                    insertGrid(grid, result, n, i, j);
                }
                jStart = 0;
            }
            // Insert the rest
            int iEnd, jEnd;
            if (jInit == 0)
            {
                iEnd = iStart - 1;
                jEnd = n - 1;
            }
            else
            {
                iEnd = iStart;
                jEnd = jInit - 1;
            }
            //std::cout << "iEnd: " << iEnd << ", jEnd: " << jEnd << std::endl;
            for (int i = 0; i <= iEnd; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    insertGrid(grid, result, n, i, j);
                    //std::cout << "i: " << i << ", j: " << j  << std::endl;
                    if (i == iEnd && j >= jEnd)
                    {
                        break;
                    }
                }
            }
        }
        else
        {
            return grid;
        }
        return result;
    }
};
