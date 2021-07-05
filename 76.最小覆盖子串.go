/*
 * @lc app=leetcode.cn id=76 lang=golang
 *
 * [76] 最小覆盖子串
 */

// @lc code=start
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
// @lc code=end

