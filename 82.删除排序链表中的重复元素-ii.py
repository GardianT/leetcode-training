#
# @lc app=leetcode.cn id=82 lang=python
#
# [82] 删除排序链表中的重复元素 II
#

# @lc code=start
# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def deleteDuplicates(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        tmp = ListNode(0)
        tmp.next = head
        head = tmp
        while head.next:
            n1, n2 = head.next, head.next
            while n2.next and n2.next.val == n1.val:
                n2 = n2.next
            if n1 != n2:
                head.next = n2.next
            else:
                head = head.next
        return tmp.next
# @lc code=end

