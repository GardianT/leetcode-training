/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */

 func dfs(root *TreeNode, cur_sum int, res *[]int) {
    if root == nil {
        return
    }
    sum := cur_sum * 10 + root.Val
    if root.Left == nil && root.Right == nil {
        *res = append(*res, sum)
    } else {
        dfs(root.Left, sum, res)
        dfs(root.Right, sum, res)
    }
}

func sumNumbers(root *TreeNode) int {
    nums, res := []int{}, 0
    dfs(root, 0, &nums)
    for _, val := range nums {
        res += val
    }
    return res
}