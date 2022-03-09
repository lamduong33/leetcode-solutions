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
        // Get all repeating members
        auto dummy = new ListNode{-101, head}, q = dummy, p = head;
        auto encountered = std::unordered_set<int>{};
        auto blackList = std::unordered_set<int>{};
        while (p != nullptr)
        {
            if (!encountered.count(p->val))
            {
                encountered.insert(p->val);
            }
            else
            {
                blackList.insert(p->val);
            }
            p = p->next;
        }
        p = head;
        while (p != nullptr)
        {
            if (blackList.count(p->val))
            {
                p = p->next;
            }
            else
            {
                q->next = p;
                q = q->next;
                p = p->next;
            }
        }
        q->next = nullptr;
        return dummy->next;
    }
};
