// Q:
// 给定一个非空字符串 s 和一个包含非空单词列表的字典 wordDict，在字符串中增加空格来构建一个句子，使得句子中所有的单词都在词典中。返回所有这些可能的句子。
// 说明：
// 分隔时可以重复使用字典中的单词。
// 你可以假设字典中没有重复的单词。
// 示例 1：
// 输入:
// s = "catsanddog"
// wordDict = ["cat", "cats", "and", "sand", "dog"]
// 输出:
// [
//   "cats and dog",
//   "cat sand dog"
// ]
// 示例 2：
// 输入:
// s = "pineapplepenapple"
// wordDict = ["apple", "pen", "applepen", "pine", "pineapple"]
// 输出:
// [
//   "pine apple pen apple",
//   "pineapple pen apple",
//   "pine applepen apple"
// ]
// 解释: 注意你可以重复使用字典中的单词。

// TLE
func recursive(s string, wordMap map[string]bool, cur_res string, res *[]string) {
    if s == "" {
        *res = append(*res, cur_res)
        return
    }
    if cur_res != "" {
        cur_res += " "
    }
    for i, _ := range s {
        cur_str := s[0:i+1]
        if _, ok := wordMap[cur_str]; ok {
            recursive(s[i+1:], wordMap, cur_res + cur_str, res)
        }
    }
}

func wordBreak(s string, wordDict []string) []string {
    wordMap := map[string]bool{}
    for _, val := range wordDict {
        wordMap[val] = true
    }
    res := []string{}
    recursive(s, wordMap, "", &res)
    return res
}