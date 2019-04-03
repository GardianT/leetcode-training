// Q：
// 给定一个字符串 s，将 s 分割成一些子串，使每个子串都是回文串。
// 返回符合要求的最少分割次数。
// 示例:
// 输入: "aab"
// 输出: 1
// 解释: 进行一次分割就可将 s 分割成 ["aa","b"] 这样两个回文子串。

// 思路：动态规划
// 字符串s长度n，初始化一个长度n的数组，每一位的值都等于它的index
// 也就是说，每个字符都分割一次，肯定是构成回文串的。
// 然后for循环判定每一位是否有构成回文串的可能性，如果有，就更新次数值。
func Reverse(s string) string {
    r := []rune(s)
    for i, j := 0, len(r)-1; i < len(r)/2; i, j = i+1, j-1 {
        r[i], r[j] = r[j], r[i]
    }
    return string(r)
}

func min(i, j int) int {
    if i > j {
        return j
    }
    return i
}

func minCut(s string) int {
	// 没有这两步预处理就会timeout我真是神他妈。
    if s == Reverse(s) {
        return 0
    }
    for i := 1; i < len(s) + 1; i++ {
        if s[:i] == Reverse(s[:i]) && s[i:] == Reverse(s[i:]) {
            return 1
        }
    }
    dp := []int{}
    for i := 0; i < len(s) + 1; i++ {
        dp = append(dp, len(s))
    }
    dp[0] = -1
    for i := 0; i < len(s); i++ {
        for j := 0; j < i + 1; j++ {
            if s[j:i+1] == Reverse(s[j:i+1]) {
                dp[i + 1] = min(dp[i + 1], dp[j] + 1)
            }
        } 
    }
    return dp[len(dp) - 1]
}