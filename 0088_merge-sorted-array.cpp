#include <iostream>
#include <vector>
#include <algorithm>

/*
** @author: Lam Duong
*/
class Solution
{
public:
    void merge(std::vector<int> &nums1, int m, std::vector<int> &nums2, int n)
    {
        // Merge the lists
        auto it2 = nums2.begin();
        for (auto it = nums1.begin()+m; it < nums1.end(); ++it)
        {
            *it = *it2;
            it2++;
        }
        sort(nums1);
        std::sort(nums1.begin(), nums1.end());
    }

    /*
    ** Quick sort
     */
    void sort(std::vector<int> &nums1)
    {

    }

};
