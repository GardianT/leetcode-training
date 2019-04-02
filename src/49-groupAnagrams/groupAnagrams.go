// Q：
// 给定一个字符串数组，将字母异位词组合在一起。字母异位词指字母相同，但排列不同的字符串。
// 示例:
// 输入: ["eat", "tea", "tan", "ate", "nat", "bat"],
// 输出:
// [
//   ["ate","eat","tea"],
//   ["nat","tan"],
//   ["bat"]
// ]

// 思路：sort后map
import "sort"
import "strings"

func sortString(s string) string {
    r := strings.Split(s, "")
    sort.Strings(r)
    return strings.Join(r, "")
}

func groupAnagrams(strs []string) [][]string {
    res := [][]string{}
    strmap := map[string][]string{}
    
    for _, val := range(strs) {
        if target, ok := strmap[sortString(val)]; ok {
            strmap[sortString(val)] = append(target, val)
        } else {
            strmap[sortString(val)] = []string{val}
        }
    }
    
    for _, v := range(strmap) {
        res = append(res, v)
    }
    
    return res
}