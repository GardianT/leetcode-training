func wordBreak(s string, wordDict []string) bool {
    wordMap := map[string]bool{}
    for _, val := range wordDict {
        wordMap[val] = true
    }
    dp := []bool{true}
    for i := 1; i < len(s) + 1; i++ {
        dp = append(dp, false)
    }
    
    for i, _ := range s {
        for j := 0; j < i + 1; j++ {
            if _, ok := wordMap[s[j:i+1]]; ok && dp[j] {
                dp[i+1] = true
                break
            }
        }
    }
    return dp[len(dp) - 1]
}