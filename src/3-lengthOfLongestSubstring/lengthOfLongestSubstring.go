// Q:
// 给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度。
// 示例 1:
// 输入: "abcabcbb"
// 输出: 3 
// 解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
// 示例 2:
// 输入: "bbbbb"
// 输出: 1
// 解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。
// 示例 3:
// 输入: "pwwkew"
// 输出: 3
// 解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
//      请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。

// 思路：用一个map随时记录字符出现位置。遍历一遍即可
func max(x, y int) int {
    if x > y {
        return x
    }
    return y
}

func lengthOfLongestSubstring(s string) int {
    smap := make(map[rune]int)
    lasti, ans := 0, 0
    for idx, chr := range(s) {
        if last_idx, ok := smap[chr]; ok {
            lasti = max(last_idx, lasti)
        }
        ans = max(ans, idx - lasti + 1)
        smap[chr] = idx + 1
    }
    return ans
}