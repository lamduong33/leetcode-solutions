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
        auto dummy = new ListNode{-101, head}, q = dummy, p = head;
        auto r = dummy->val;
        while (p != nullptr)
        {
            if (p->val != r)
            {
                r = p->val;
                if (p->next != nullptr)
                {
                    if (p->next->val != r)
                    {
                        q->next = p;
                        q = q->next;
                    }
                }
            }
            if ((p->next == nullptr) && (p != q->next))
            {
                q->next = nullptr;
            }
            p = p->next;
        }
        return dummy->next;
    }
};
