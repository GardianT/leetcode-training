// Q:
// 给定两个字符串 s 和 t ，编写一个函数来判断 t 是否是 s 的一个字母异位词。
// 示例 1:
// 输入: s = "anagram", t = "nagaram"
// 输出: true
// 示例 2:
// 输入: s = "rat", t = "car"
// 输出: false

func isAnagram(s string, t string) bool {
    maps := map[rune]int{}
    for _, v := range s {
        if _, ok := maps[v]; ok {
            maps[v]++
        } else {
            maps[v] = 1
        }
    }
    for _, v := range t {
        if _, ok := maps[v]; ok {
            if maps[v] > 0 {
                maps[v]--
            } else {
                return false
            }
        } else {
            return false
        }
    }
    for _, v := range maps {
        if v > 0 {
            return false
        }
    }
    return true
}