# Definition for singly-linked list.
class ListNode:
     def __init__(self, val=0, next=None):
         self.val = val
         self.next = next
class Solution:
    def deleteDuplicates(self, head: ListNode) -> ListNode:
        """ Delete the duplicate"""
        if (head == None):
            return head
        hashed_set = set()
        hashed_set.add(head.val) # Handle first elemetn
        temp = head
        while (temp.next != None):
            # If the element has been seen before
            if (temp.next.val) in hashed_set:
                temp.next = temp.next.next
            else:
                hashed_set.add(temp.next.val)
                temp = temp.next
        if (temp.val in hashed_set): #handle last element
            temp = None
        return head
