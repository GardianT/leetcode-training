#
# @lc app=leetcode.cn id=2 lang=python
#
# [2] 两数相加
#

# @lc code=start
# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def addTwoNumbers(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        carry = 0
        head = ListNode()
        res = head
        while l1 or l2:
            tmp = ListNode(0)
            val = carry
            if l1:
                val += l1.val
                l1 = l1.next
            if l2:
                val += l2.val
                l2 = l2.next
            if val >= 10:
                val %= 10
                carry = 1
            else:
                carry = 0
            tmp.val = val
            head.next = tmp
            head = head.next
        if carry:
            head.next = ListNode(1)
        return res.next
# @lc code=end

