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
        auto dummy = new ListNode{101, head}, pointer1 = dummy, pointer2 = head;
        int repeating = -101;
        while (pointer2 != nullptr)
        {
            if (pointer2->next != nullptr)
            {
                // If they are the same value. This means this is a repeat.
                if (pointer2->val == pointer2->next->val)
                {
                    pointer2 = pointer2->next;
                    repeating = pointer2->val;
                }
                else
                {
                    // Not a repeat. But there are two cases. One is that the
                    // next one will repeat. The other is that it does not.
                    if (pointer2->next->next != nullptr)
                    {
                        if (pointer2->next->val == pointer2->next->next->val)
                        {
                            pointer2 = pointer2->next;
                        }
                        else
                        {
                            pointer1->next = pointer2->next;
                            pointer1 = pointer1->next; // only advance if the
                                                       // next sequence is not a
                                                       // repeating sequence
                            pointer2 = pointer2->next->next;
                        }
                    }
                }
            }
        }
        return dummy->next;
    }
};
