#include <iostream>
/**
 * Definition for singly-linked list.*/
// struct ListNode
// {
//     int val;
//     ListNode* next;
//     ListNode() : val(0), next(nullptr) {}
//     ListNode(int x) : val(x), next(nullptr) {}
//     ListNode(int x, ListNode* next) : val(x), next(next) {}
// };

class Solution
{
    void swap(ListNode* node1, ListNode* node2)
    {
        if (node2 != nullptr)
        {
            node1->next = node2->next;
            node2->next = node1;
        }
    }

public:
    ListNode* swapPairs(ListNode* head)
    {
        auto result = head;
        if ((head != nullptr) && (head->next != nullptr))
        {
            result = head->next;
            auto pointer = head;
            while (pointer != nullptr)
            {
                swap(pointer, pointer->next);
                auto temp = pointer->next;
                if (pointer->next != nullptr && pointer->next->next != nullptr)
                    pointer->next = pointer->next->next;
                pointer = temp;
            }
        }
        return result;
    }
};
