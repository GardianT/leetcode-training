# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def mergeTwoLists(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        if l1 is None:
            return l2
        if l2 is None:
            return l1
        
        head = ListNode(0)
        res = head
        while l1 is not None and l2 is not None:
            if l1.val > l2.val:
                head.next = l2
                l2 = l2.next
            else:
                head.next = l1
                l1 = l1.next
            head = head.next
        while l1 is not None:
            head.next = l1
            l1 = l1.next
            head = head.next
        while l2 is not None:
            head.next = l2
            l2 = l2.next
            head = head.next
        return res.next
            