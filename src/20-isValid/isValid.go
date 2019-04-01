// Q：
// 给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串，判断字符串是否有效。
// 有效字符串需满足：
// 左括号必须用相同类型的右括号闭合。
// 左括号必须以正确的顺序闭合。
// 注意空字符串可被认为是有效字符串。
// 示例 1:
// 输入: "()"
// 输出: true
// 示例 2:
// 输入: "()[]{}"
// 输出: true
// 示例 3:
// 输入: "(]"
// 输出: false
// 示例 4:
// 输入: "([)]"
// 输出: false
// 示例 5:
// 输入: "{[]}"
// 输出: true

// 思路：用一个栈，左括号都放栈内，不是左括号就跟栈顶比较。
func isValid(s string) bool {
    if s == "" {
        return true
    }
    
    if len(s) % 2 == 1 {
        return false
    }
    
    match_map := map[rune]rune{'(': ')', '{': '}', '[': ']'}
    pop_stack := []rune{}
    
    for _, chr := range(s) {
        if _, ok := match_map[chr]; ok {
            pop_stack = append(pop_stack, chr)
        } else if len(pop_stack) >= 1 && chr == match_map[pop_stack[len(pop_stack) - 1]] {
            pop_stack = pop_stack[:len(pop_stack) - 1]       
        } else {
            return false
        }
    }
    
    return len(pop_stack) == 0
}