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