// Q：
// 给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。
// 给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。
// 示例:
// 输入："23"
// 输出：["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].

// 思路：遍历就行了
func letterCombinations(digits string) []string {
    if len(digits) == 0 {
        return []string{}
    }
    
    number_map := []string{"", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"}
    res := []string{""}
    for _, val := range(digits) {
        tmp := []string{}
        target_chars := number_map[int(val - '1')]
        for _, char := range(target_chars) {
            for _, tmp_str := range(res) {
                tmp = append(tmp, tmp_str + string(char))
            }
        }
        res = tmp
    }
    return res
}