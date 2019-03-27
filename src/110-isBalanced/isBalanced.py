# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def MaxDepth(self, root):
        if not root:
            return 0
        return max(self.MaxDepth(root.left) + 1, self.MaxDepth(root.right) + 1)
    
    def isBalanced(self, root):
        """
        :type root: TreeNode
        :rtype: bool
        """
        if not root:
            return True
        
        return abs(self.MaxDepth(root.left) - self.MaxDepth(root.right)) <= 1 \
                and self.isBalanced(root.left) and self.isBalanced(root.right)