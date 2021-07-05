#
# @lc app=leetcode.cn id=86 lang=python
#
# [86] 分隔链表
#

# @lc code=start
# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def partition(self, head, x):
        """
        :type head: ListNode
        :type x: int
        :rtype: ListNode
        """
        tmp1, tmp2 = ListNode(0), ListNode(0)
        n1, n2 = tmp1, tmp2
        while head:
            if head.val < x:
                n1.next = head
                head = head.next
                n1 = n1.next
                n1.next = None
            else:
                n2.next = head
                head = head.next
                n2 = n2.next
                n2.next = None
            
        n1.next = tmp2.next
        return tmp1.next
# @lc code=end

