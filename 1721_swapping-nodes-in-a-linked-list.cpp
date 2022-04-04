/**
 * Definition for singly-linked list. */
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
public:
    ListNode* swapNodes(ListNode* head, int k)
    {
        auto size = 0;
        auto p = head;

        // Get size
        while (p != nullptr)
        {
            size++;
            p = p->next;
        }
        if (size == 1) return head;

        // Swap the neccessary
        auto second = size - k + 1, count = 1;
        ListNode *start = nullptr, *end = nullptr;
        p = head;

        while (p != nullptr)
        {
            if (count == k) // at the first node to be swapped
                start = p;
            if (count == second)
                end = p;
            count++;
            p = p->next;
        }
        auto temp = start->val;
        start->val = end->val;
        end->val = temp;

        return head;
    }
};
