class Solution
{
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals)
    {
        int count = intervals.size();
        std::sort(intervals.begin(), intervals.end(),
                  [](const vector<int>& a, const vector<int>& b)
                  {
                      if (a[0] == b[0])
                          return a[1] > b[1];
                      else
                          return a[0] < b[0];
                  });
        auto c = -1, d = -1;

        for (int i = 0; i < intervals.size(); i++)
        {
            int a = intervals[i][0], b = intervals[i][1];
            if (c <= a && b <= d)
            {
                count--;
            }
            else
            {
                c = intervals[i][0];
                d = intervals[i][1];
            }
        }

        return count;
    }
};
