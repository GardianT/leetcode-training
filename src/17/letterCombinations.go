func letterCombinations(digits string) []string {
    if len(digits) == 0 {
        return []string{}
    }
    
    number_map := []string{"", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"}
    res := []string{""}
    for _, val := range(digits) {
        tmp := []string{}
        target_chars := number_map[int(val - '1')]
        for _, char := range(target_chars) {
            for _, tmp_str := range(res) {
                tmp = append(tmp, tmp_str + string(char))
            }
        }
        res = tmp
    }
    return res
}