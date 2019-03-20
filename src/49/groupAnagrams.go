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