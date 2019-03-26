/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
 func genTree(l, r int) []*TreeNode {
    if l > r {
        return []*TreeNode{nil}
    }
    
    res := []*TreeNode{}
    for i := l; i <= r; i++ {
        left_trees := genTree(l, i - 1)
        right_trees := genTree(i + 1, r)
        for _, lt := range left_trees {
            for _, rt := range right_trees {
                tree := &TreeNode{Val: i}
                tree.Left = lt
                tree.Right = rt
                res = append(res, tree)
            }
        }
    }
    return res
}

func generateTrees(n int) []*TreeNode {
    if n == 0 {
        return []*TreeNode{}
    }
    return genTree(1, n)
}

