class Solution
{
public:
    // Dynamic programming appraoch
    int climbStairs(int n)
    {
        if (n < 3)
            return n;
        std::list<std::pair<int, int>> paths;
        std::list<std::pair<int, int>> newPaths;
        paths.push_back(std::pair{1, 2});
        paths.push_back(std::pair{0, 2});

        for (int i = 3; i <= n; i++)
        {
            for (auto& path : paths)
            {
                if (path.second - path.first == 1)
                {
                    newPaths.push_back(std::pair<int,int>{path.first, i});
                }
                path.first = path.second;
                path.second = i;
            }
            paths.merge(newPaths);
            newPaths.clear();
        }

        return (int)paths.size();
    }
};
