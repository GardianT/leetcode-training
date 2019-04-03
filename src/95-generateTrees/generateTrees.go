// Q：
// 给定一个整数 n，生成所有由 1 ... n 为节点所组成的二叉搜索树。
// 示例:
// 输入: 3
// 输出:
// [
//   [1,null,3,2],
//   [3,2,null,1],
//   [3,1,null,null,2],
//   [2,1,3],
//   [1,null,2,null,3]
// ]
// 解释:
// 以上的输出对应以下 5 种不同结构的二叉搜索树：
//    1         3     3      2      1
//     \       /     /      / \      \
//      3     2     1      1   3      2
//     /     /       \                 \
//    2     1         2                 3

// 思路：围绕根节点展开，以3举例
// 比如以2为根节点，剩下的[1, 2)构建左子树，剩下的(2, 3]构建右子树
// 递归这个操作下去。
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

