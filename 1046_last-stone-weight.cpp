// #include <algorithm>
// #include <queue>
// #include <vector>
// #include <iostream>
// using std::vector;

class Solution
{
public:
    int lastStoneWeight(vector<int>& stones)
    {
        std::priority_queue<int> pq(stones.begin(), stones.end()); // maxheap
        while (pq.size() > 1)
        {
            int y = pq.top();
            pq.pop();
            int x = pq.top();
            pq.pop();
            if (x != y)
            {
                pq.push(y-x);
            }
        }
        if (pq.empty()) pq.push(0);
        return pq.top();
    }
};
