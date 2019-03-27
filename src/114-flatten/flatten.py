# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def flatten(self, root):
        """
        :type root: TreeNode
        :rtype: None Do not return anything, modify root in-place instead.
        """
        if root is None:
            return
        
        self.flatten(root.left)
        self.flatten(root.right)
        
        if root.left:
            right = root.right
            root.right = root.left
            root.left = None
            temp = root.right
            while temp.right:
                temp = temp.right
            temp.right = right