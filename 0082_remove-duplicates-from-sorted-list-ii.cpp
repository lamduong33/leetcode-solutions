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
    ListNode* deleteDuplicates(ListNode* head)
    {
        auto dummy = new ListNode{-101, head}, b = dummy, q = dummy, p = head;
        auto r = dummy->val;
        while (p != nullptr)
        {
            if (q->val == p->val)
            {
                r = q->val;
            }
            else
            {
                if (q->val != r)
                {
                    b->next = q;
                    b = q;
                }
                q = p;
            }
            p = p->next;
        }
        if (q->val != r)
        {
            b->next = q;
        }
        else {
            b->next = nullptr;
        }
        return dummy->next;
    }
};
