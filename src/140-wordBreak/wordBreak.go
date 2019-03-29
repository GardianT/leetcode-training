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