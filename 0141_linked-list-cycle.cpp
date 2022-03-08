/**
 * Definition for singly-linked list. */
// struct ListNode
// {
//     int val;
//     ListNode* next;
//     ListNode(int x) : val(x), next(NULL) {}
// };

class Solution
{
public:
    bool hasCycle(ListNode* head)
    {
        if (head == nullptr) return false;
        auto result = false;
        auto p1 = head, p2 = head->next;
        while (p2 != nullptr)
        {
            if (p2->next == nullptr || p2->next->next == nullptr)
            {
                break;
            }
            if (p1 == p2)
            {
                result = true;
                break;
            }
            p1 = p1->next;
            p2 = p2->next->next;
        }
        return result;
    }
};
