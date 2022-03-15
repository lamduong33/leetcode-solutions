#include <list>
#include <vector>
#include <iostream>

class Solution
{
public:
    // Dynamic programming appraoch
    int climbStairs(int n)
    {
        if (n < 3) return n;
        std::vector<std::pair<int,int>> paths;
        std::vector<std::pair<int,int>> newPaths;
        paths.push_back(std::pair{1, 2});
        paths.push_back(std::pair{0, 2});

        for (int i = 3; i <= n; i++)
        {
            for (auto& path : paths)
            {
                if (path.second - path.first == 1)
                {
                    // FIXME: Memory error: can't write while accessing
                    newPaths.push_back(std::pair<int, int>{path.second, i});
                }
                path.first = path.second;
                path.second = i;
            }
            paths.insert(paths.end(), newPaths.begin(), newPaths.end());
            newPaths.clear();
        }

        return (int)paths.size();
    }
};
