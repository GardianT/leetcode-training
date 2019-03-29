/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */

 func recursive(root *TreeNode, res *[]int) {
    if root == nil {
        return
    }
    *res = append(*res, root.Val)
    recursive(root.Left, res)
    recursive(root.Right, res)
}

func preorderTraversal(root *TreeNode) []int {
    res := []int{}
    recursive(root, &res)
    return res
}