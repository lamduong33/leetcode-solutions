#include <iostream>
#include <unordered_map>

// Definition for singly-linked list.
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
    /* Dumb solution */
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    {
        ListNode* finalList = new ListNode();
        ListNode* nodeptr; // the current node being worked

        // Get the size
        int size1 = getSize(l1);
        int size2 = getSize(l2);
        int biggest = (size1 > size2 ? size1 : size2);

        // Calculation
        bool carry = false;
        nodeptr = finalList;

        for (int i = 0; i <= biggest; i++)
        {
            int firstVal = (l1 != NULL ? l1->val : 0);
            int secondVal = (l2 != NULL ? l2->val : 0);
            int additionResult = firstVal + secondVal + carry;
            if (additionResult >= 10)
            {
                additionResult -= 10;
                carry = true;
            }
            else
            {
                carry = false;
            }
            nodeptr->val = additionResult;

            // Pointer logic
            if (l1 != NULL)
                l1 = l1->next;
            if (l2 != NULL)
                l2 = l2->next;
            if ((l1 == NULL) && (l2 == NULL) && (carry == false))
                break; // Don't continue if both are done and there's no carry
            ListNode* nextNode = new ListNode();
            nodeptr->next = nextNode;
            nodeptr = nextNode;
        }

        return finalList;
    }

    /* Helper function to get size */
    int getSize(ListNode* list)
    {
        int size = 1;
        while (list->next != nullptr)
        {
            list = list->next;
            size++;
        }
        return size;
    }
};
