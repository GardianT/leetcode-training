// Q：
// 给定一个只包含 '(' 和 ')' 的字符串，找出最长的包含有效括号的子串的长度。
// 示例 1:
// 输入: "(()"
// 输出: 2
// 解释: 最长有效括号子串为 "()"
// 示例 2:
// 输入: ")()())"
// 输出: 4
// 解释: 最长有效括号子串为 "()()"

// 思路：用一个栈记录括号位置，每匹配成功一个括号，就把左右括号出现的位置放到一个数组里。
// 数组排序以后，他的最大连续区间就是最长有效括号串。
import "sort"

func max(i, j int) int {
    if i > j {
        return i
    }
    return j
}

func longestValidParentheses(s string) int {
    if len(s) == 0 {
        return 0
    }
    
    st, bitmap := []int{}, []int{}
    for i, val := range(s) {
        if (val == '(') {
            st = append(st, i)
        } else if (len(st) > 0) {
            bitmap = append(bitmap, st[len(st) - 1])
            bitmap = append(bitmap, i)
            st = st[:len(st) - 1]
        }
    }
    if len(bitmap) == 0 {
        return 0
    }
    sort.Sort(sort.IntSlice(bitmap))
    tmp, res := 1, 0
    for i := 1; i < len(bitmap); i++ {
        if bitmap[i] == bitmap[i - 1] + 1 {
           tmp += 1 
        } else {
            res = max(res, tmp)
            tmp = 1
        }
    }
    return max(tmp, res)
}