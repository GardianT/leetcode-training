# Q:
# 合并 k 个排序链表，返回合并后的排序链表。请分析和描述算法的复杂度。
# 示例:
# 输入:
# [
#   1->4->5,
#   1->3->4,
#   2->6
# ]
# 输出: 1->1->2->3->4->4->5->6

# 思路：两两归并

# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def mergeKLists(self, lists):
        """
        :type lists: List[ListNode]
        :rtype: ListNode
        """
        def mergeTwoList(list1, list2):
            dummy = ListNode(0)
            res = dummy
            while list1 is not None and list2 is not None:
                if list1.val < list2.val:
                    dummy.next = list1
                    list1 = list1.next
                else:
                    dummy.next = list2
                    list2 = list2.next
                dummy = dummy.next
            if list1 is not None:
                dummy.next = list1
            elif list2 is not None:
                dummy.next = list2
            return res.next
        
        if len(lists) == 0:
            return None
        
        if len(lists) == 1:
            return lists[0]
        
        i = 0
        tmp = []
        for i in range(0, len(lists) - 1, 2):
            tmp.append(mergeTwoList(lists[i], lists[i + 1]))
        # 处理奇数
        if i + 2 != len(lists):
            tmp.append(lists[-1])
        return self.mergeKLists(tmp)