# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def pathSum(self, root, sum):
        """
        :type root: TreeNode
        :type sum: int
        :rtype: List[List[int]]
        """
        res = []
        if not root:
            return res
        
        def getPath(node, cur_path, target):
            if not node:
                return
            
            left = target - node.val
            path = cur_path[:]
            path.append(node.val)

            if left == 0:
                if not node.left and not node.right:
                    res.append(path)
                    return
            
            getPath(node.left, path, left)
            getPath(node.right, path, left)
        
        getPath(root, [], sum)
        return res