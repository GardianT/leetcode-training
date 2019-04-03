// Q:
// 给定一个二叉树，返回它的 前序 遍历。
//  示例:
// 输入: [1,null,2,3]  
//    1
//     \
//      2
//     /
//    3 
// 输出: [1,2,3]

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