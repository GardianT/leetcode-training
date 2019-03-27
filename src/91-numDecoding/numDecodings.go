func numDecodings(s string) int {
    dp := []int{1, 1}
    for i, v := range s {
        res := dp[len(dp) - 1]
        if v == '0' {
            res = 0
        }
        if i > 0 && (s[i - 1] == '1' || (v <= '6' && s[i-1] == '2')) {
            res += dp[len(dp) - 2]
        }
        dp = append(dp, res)
    }
    return dp[len(dp) - 1]
}