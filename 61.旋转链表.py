#
# @lc app=leetcode.cn id=61 lang=python
#
# [61] 旋转链表
#

# @lc code=start
# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def rotateRight(self, head, k):
        """
        :type head: ListNode
        :type k: int
        :rtype: ListNode
        """
        if not head or k == 0:
            return head
        n = 1
        tmp = head
        while tmp.next:
            n += 1
            tmp = tmp.next 
        k %= n
        if not k:
            return head
        l1, l2 = head, head
        while k:
            l1 = l1.next
            k -= 1
        while l1.next:
            l1 = l1.next
            l2 = l2.next
        res = l2.next
        l2.next = None
        tmp.next = head
        return res
# @lc code=end

