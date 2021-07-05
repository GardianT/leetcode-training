#
# @lc app=leetcode.cn id=19 lang=python
#
# [19] 删除链表的倒数第N个节点
#

# @lc code=start
# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def removeNthFromEnd(self, head, n):
        """
        :type head: ListNode
        :type n: int
        :rtype: ListNode
        """
        l1, l2 = head, head
        while n > 0:
            if l1.next == None:
                return l2.next
            l1 = l1.next
            n -= 1
        while l1.next != None:
            l1 = l1.next
            l2 = l2.next 
        l2.next = l2.next.next
        return head
# @lc code=end

