// Q：
// 给出 n 代表生成括号的对数，请你写出一个函数，使其能够生成所有可能的并且有效的括号组合。
// 例如，给出 n = 3，生成结果为：
// [
//   "((()))",
//   "(()())",
//   "(())()",
//   "()(())",
//   "()()()"
// ]

// 思路：递归就行
func recursive(left, right int, num int, item string, res *[]string) {
    if left == num && right == num {
        *res = append(*res, item)
        return
    }
    
    if left < num {
        recursive(left + 1, right, num, item + "(", res)
    }
    if right < left {
        recursive(left, right + 1, num, item + ")", res)
    }
    
}

func generateParenthesis(n int) []string {
    res := []string{}
    recursive(0, 0, n, "", &res)
    return res
}