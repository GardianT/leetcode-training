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