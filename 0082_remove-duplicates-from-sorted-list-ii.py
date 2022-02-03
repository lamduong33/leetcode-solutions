# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
class Solution:
    def deleteDuplicates(self, head: ListNode) -> ListNode:
        if(head == None):
            return head
        checker = head
        hashed_set = set()
        while (checker.next != None):
            if (checker.next.val == checker.val):
                hashed_set.add(checker.val)
            checker = checker.next

        dummy = ListNode(101)
        new_curr = dummy
        curr = head
        while (curr != None):
            if curr.val not in hashed_set:
                new_curr.next = ListNode(curr.val)
                new_curr = new_curr.next
            curr = curr.next
        return dummy.next

