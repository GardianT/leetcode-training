// Q:
// 给定一个非空字符串 s 和一个包含非空单词列表的字典 wordDict，判定 s 是否可以被空格拆分为一个或多个在字典中出现的单词。
// 说明：
// 拆分时可以重复使用字典中的单词。
// 你可以假设字典中没有重复的单词。
// 示例 1：
// 输入: s = "leetcode", wordDict = ["leet", "code"]
// 输出: true
// 解释: 返回 true 因为 "leetcode" 可以被拆分成 "leet code"。
// 示例 2：
// 输入: s = "applepenapple", wordDict = ["apple", "pen"]
// 输出: true
// 解释: 返回 true 因为 "applepenapple" 可以被拆分成 "apple pen apple"。
//      注意你可以重复使用字典中的单词。
// 示例 3：
// 输入: s = "catsandog", wordDict = ["cats", "dog", "sand", "and", "cat"]
// 输出: false

// 思路：动态规划，两次遍历找所有可能出现的字符串去匹配词典即可。
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