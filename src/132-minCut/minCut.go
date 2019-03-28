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