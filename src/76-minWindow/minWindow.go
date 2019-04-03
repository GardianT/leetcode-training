// Q：
// 给定一个字符串 S 和一个字符串 T，请在 S 中找出包含 T 所有字母的最小子串。
// 示例：
// 输入: S = "ADOBECODEBANC", T = "ABC"
// 输出: "BANC"

// 思路：双指针。一个l和一个r。如果s[l:r]已经包含了子串b，让l往右走，缩小这个子串。
// 否则r往右走，继续搜寻。
// not accept. timeout.

func containChars(a, b string) bool {
    mapb := map[rune]int{}
    for _, val := range(b) {
        if _, ok := mapb[val]; ok {
            mapb[val]++
        } else {
            mapb[val] = 1
        }
    }
    
    for _, val := range(a) {
        if _, ok := mapb[val]; ok {
            if mapb[val] > 0 {
                mapb[val]--
            }
        }
    }
    
    for _, val := range(mapb) {
        if val > 0 {
            return false
        }   
    }
    return true
}

func minWindow(s string, t string) string {
    len1, len2 := len(s), len(t)
    if len2 > len1 {
        return ""
    }
    l, r, res := 0, len2, ""
    for {
        if r <= len1 {
            var target string
            if (r - l) >= len2 {
                target = s[l:r]
                if containChars(target, t) {
                    if len(target) == len2 {
                        return target
                    }
                    if len(target) < len(res) || res == "" {
                        res = target
                    } else {
                        l++
                    }
                } else {
                    r++
                }
            } else {
                break
            }
        } else {
            break
        }
    }
    return res
}