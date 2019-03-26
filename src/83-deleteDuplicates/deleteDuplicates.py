# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def deleteDuplicates(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        if head is None:
            return head
        temp = head
        while temp is not None:
            if temp.next is None:
                break
            elif temp.next.val == temp.val:
                temp.next = temp.next.next
            else:
                temp = temp.next
        return head