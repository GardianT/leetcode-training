#
# @lc app=leetcode.cn id=25 lang=python
#
# [25] K 个一组翻转链表
#

# @lc code=start
# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def reverseKGroup(self, head, k):
        """
        :type head: ListNode
        :type k: int
        :rtype: ListNode
        """
        tmp = head
        for i in range(k):
            if tmp == None:
                return head
            tmp = tmp.next
        
        tmp = head
        for i in range(k - 1):
            node2 = tmp.next
            tmp.next, head, node2.next = node2.next, node2, head
        tmp.next = self.reverseKGroup(tmp.next, k)
        return head

# @lc code=end

