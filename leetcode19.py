# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def removeNthFromEnd(self, head, n):
        """
        :type head: ListNode
        :type n: int
        :rtype: ListNode
        """
        fast=head
        slow=head
        while(n!=0):
            fast=fast.next
            n-=1
        if(fast==None):
            return head.next
        while(fast.next!=None):
            fast=fast.next
            slow=slow.next
        slow.next=slow.next.next
        return head