# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def addTwoNumbers(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        tmp = ListNode(0)
        res = tmp
        carry = 0
        while l1 or l2:
            l1val = l1.val if l1 else 0
            l2val = l2.val if l2 else 0
            val = carry + l1val + l2val
            if val >= 10:
                carry = 1
                val %= 10
            else:
                carry = 0
            tmp.next = ListNode(val)
            tmp = tmp.next
            if l1:
                l1 = l1.next
            if l2:
                l2 = l2.next
        if carry == 1:
            tmp.next = ListNode(1)
        return res.next