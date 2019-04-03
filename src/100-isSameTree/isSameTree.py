# 给定两个二叉树，编写一个函数来检验它们是否相同。
# 如果两个树在结构上相同，并且节点具有相同的值，则认为它们是相同的。
# 示例 1:
# 输入:       1         1
#           / \       / \
#          2   3     2   3

#         [1,2,3],   [1,2,3]
# 输出: true
# 示例 2:
# 输入:      1          1
#           /           \
#          2             2

#         [1,2],     [1,null,2]
# 输出: false
# 示例 3:
# 输入:       1         1
#           / \       / \
#          2   1     1   2

#         [1,2,1],   [1,1,2]
# 输出: false

# 思路：递归。如果根节点开始match，开始比较左右子树；如果根节点不match，在左子树或者右子树继续搜寻。
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def isSameTree(self, p, q):
        """
        :type p: TreeNode
        :type q: TreeNode
        :rtype: bool
        """
        if not p and not q:
            return True
        if not p or not q:
            return False
        
        if p.val == q.val:
            matched = self.isSameTree(p.left, q.left) and self.isSameTree(p.right, q.right)
            if matched:
                return True
        return self.isSameTree(p.left, q) or self.isSameTree(p.right, q)