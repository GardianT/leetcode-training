#
# @lc app=leetcode.cn id=24 lang=python
#
# [24] 两两交换链表中的节点
#

# @lc code=start
# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def swapPairs(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        res = ListNode(0)
        res.next = head
        p = res
        while p.next and p.next.next:
            node1, node2, node3 = p.next, p.next.next, p.next.next.next
            node2.next, node1.next, p.next = node1, node3, node2
            p = node1 
        return res.next
# @lc code=end

