#
# @lc app=leetcode.cn id=142 lang=python
#
# [142] 环形链表 II
#

# 快慢指针第一步确认是否有环
# 如果有环，新起一个指针和慢指针同步走，遇到的位置就是起点
# @lc code=start
# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def detectCycle(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        l1, l2 = head, head
        has_cycle = False
        while l1 and l2:
            l1 = l1.next
            l2 = l2.next
            if l2:
                l2 = l2.next
            else:
                return None
            if l1 == l2:
                has_cycle = True
                break
        if has_cycle:
            res = head
            while res != l1:
                res = res.next
                l1 = l1.next
            return res;
        else:
            return None
# @lc code=end

