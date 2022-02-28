#include <vector>
#include <bits/stdc++.h>
#include <iostream>
/**
 * Definition for singly-linked list.*/
// struct ListNode {
//     int val;
//     ListNode *next;
//     ListNode() : val(0), next(nullptr) {}
//     ListNode(int x) : val(x), next(nullptr) {}
//     ListNode(int x, ListNode *next) : val(x), next(next) {}
// };

class Solution
{
public:
    ListNode* sortList(ListNode* head)
    {
        auto heap = std::vector<ListNode*>{};
        auto pointer = head;
        while (pointer != nullptr)
        {
            heap.push_back(pointer);
            pointer = pointer->next;
        }

        // Heap construction
        std::make_heap(heap.begin(), heap.end(),
                       [] (const ListNode* node1, ListNode* node2)
                       {
                           return node1->val < node2->val;
                       });


        // Heap construction
        std::sort_heap(heap.begin(), heap.end(),
                       [] (const ListNode* node1, ListNode* node2)
                       {
                           return node1->val < node2->val;
                       });

        // Construct list from heap
        auto newList = new ListNode{};
        auto newHead = newList;
        for (auto node : heap)
        {
            newHead->next = new ListNode{node->val};
            newHead = newHead->next;
        }
        newList = newList->next;
        return newList;
    }
};
