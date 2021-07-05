#
# @lc app=leetcode.cn id=141 lang=python
#
# [141] 环形链表
#

# @lc code=start
# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def hasCycle(self, head):
        """
        :type head: ListNode
        :rtype: bool
        """
        l1, l2 = head, head
        while l1 and l2:
            l1 = l1.next
            l2 = l2.next
            if l2:
                l2 = l2.next
            else:
                return False
            if l1 == l2:
                return True
        return False        
# @lc code=end

