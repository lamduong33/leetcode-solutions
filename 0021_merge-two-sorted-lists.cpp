#include <iostream>
#include <memory>
#include <string>

// Definition for singly-linked list.
// struct ListNode
// {
//     int val;
//     ListNode *next;
//     ListNode() : val(0), next(nullptr) {}
//     ListNode(int x) : val(x), next(nullptr) {}
//     ListNode(int x, ListNode *next) : val(x), next(next) {}
// };

class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {
        if ((l1 == nullptr) && (l2 == nullptr))
        {
            return nullptr;
        }
        else if ((l1 != nullptr) && (l2 == nullptr))
        {
            return l1;
        }
        if ((l1 == nullptr) && (l2 != nullptr))
        {
            return l2;
        }

        // Pick a list to be the result to be manipulated. Smaller one first.
        ListNode *head = (l1->val <= l2->val) ? l1 : l2;
        ListNode *otherList = (l1->val <= l2->val) ? l2 : l1;
        auto result = head;

        while (head != nullptr)
        {
            if (head->next != nullptr)
            {
                if (head->next->val <= otherList->val)
                {
                    head = head->next;
                }
                else
                {
                    // NOTE: This might be a bottleneck due to instantiations.
                    head->next = new ListNode(otherList->val, head->next);
                    head = head->next;
                    if (otherList->next != nullptr)
                    {
                        otherList = otherList->next;
                    }
                    else
                    {
                        // Reached thee end of the main list
                        break;
                    }
                }
            }
            else
            {
                // Reached the end of the main list
                head->next = otherList;
                break;
            }
        }

        return result;
    }
};
