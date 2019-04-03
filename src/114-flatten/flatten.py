# Q:
# 给定一个二叉树，原地将它展开为链表。
# 例如，给定二叉树
#     1
#    / \
#   2   5
#  / \   \
# 3   4   6
# 将其展开为：
# 1
#  \
#   2
#    \
#     3
#      \
#       4
#        \
#         5
#          \
#           6

# flatten是个在实际工程中比较重要的概念。
# 比如很多分布式计算的场景，会使用map结构用于加快处理速度，最后用flatten操作来全局遍历。

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
            right, root.right, root.left = root.right, root.left, None
            temp = root.right
            while temp.right:
                temp = temp.right
            temp.right = right