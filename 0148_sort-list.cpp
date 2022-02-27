#include <vector>
#include <bits/stdc++.h>
/**
 * Definition for singly-linked list.*/
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode* sortList(ListNode* head)
    {
        // 1) Heap construction
        auto heap = std::vector<int>{};
        auto pointer = head;
        while (pointer != nullptr)
        {
            heap.push_back(pointer->val);
            pointer = pointer->next;
        }
        std::make_heap(heap.begin(), heap.end());

        // 2) Maximum deletions
        return head;
    }
};
