// Q：
// 给定一个字符串 s，找到 s 中最长的回文子串。你可以假设 s 的最大长度为 1000。
// 示例 1：
// 输入: "babad"
// 输出: "bab"
// 注意: "aba" 也是一个有效答案。
// 示例 2：
// 输入: "cbbd"
// 输出: "bb"

// 思路：每个字符从中间位置开始向两边找回文串。貌似是最容易理解也是复杂度最低的算法。
// 由于 aba 和 aa 这种都是回文串，所以找回文串的起始点也需要注意下。
func maxExpandAroundCenter(s string, left, right int) int {
    l, r := left, right
    for {
        if l < 0 || r >= len(s) || s[l] != s[r] {
            break
        }
        l--
        r++
    }
    return r - l - 1;
}

func max(i, j int) int {
    if i > j {
        return i
    }
    return j
}

func longestPalindrome(s string) string {
    if len(s) <= 1 {
        return s
    }
    
    start, end := 0, 0
    for i := 0; i < len(s); i++ {
        var len1 int = maxExpandAroundCenter(s, i, i)
        var len2 int = maxExpandAroundCenter(s, i, i + 1)
        var maxlen int = max(len1, len2)
        if maxlen > end - start {
            start = i - (maxlen - 1) / 2
            end = i + maxlen / 2
        }
    }
    
    return string(s[start:end + 1])
}