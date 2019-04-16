// Q:
// 给定一个二叉搜索树, 找到该树中两个指定节点的最近公共祖先。

/**
 * Definition for TreeNode.
 * type TreeNode struct {
 *     Val int
 *     Left *ListNode
 *     Right *ListNode
 * }
 */
 func findTarget(root, target *TreeNode) bool {
    if root == target {
        return true
    } else if root == nil {
        return false
    } else {
        return findTarget(root.Left, target) || findTarget(root.Right, target)
    }
}

func lowestCommonAncestor(root, p, q *TreeNode) *TreeNode {
    if p == root {
        if findTarget(root.Left, q) || findTarget(root.Right, q) {
            return root
        }
    } else if q == root {
        if findTarget(root.Left, p) || findTarget(root.Right, p) {
            return root
        }
    } else if root == nil {
        return root
    }
    
	if (findTarget(root.Left, p) && findTarget(root.Right, q)) || 
		(findTarget(root.Right, p) && findTarget(root.Left, q)) {
        return root
    }
    
    leftFind := lowestCommonAncestor(root.Left, p, q)
    rightFind := lowestCommonAncestor(root.Right, p, q)
    if leftFind != nil {
        return leftFind
    } else {
        return rightFind
    }
}