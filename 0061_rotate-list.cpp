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
public:
    ListNode* rotateRight(ListNode* head, int k)
    {
        if (head == nullptr || head == nullptr)
            return head;
        auto start = head, end = head;
        auto size = 0;

        // Make list cyclical by getting to the end and point to start
        while (end != nullptr)
        {
            size++;
            if (end->next == nullptr)
            {
                end->next = start;
                break;
            }
            end = end->next;
        }

        // Rotate the list k mod size times
        auto times = size - (k % size);
        for (int i = 0; i < times; i++)
        {
            start = start->next;
        }

        // Unlink the end
        end = start;
        for (int i = 0; i < size - 1; i++)
        {
            end = end->next;
        }
        end->next = nullptr;

        return start;
    }
};
