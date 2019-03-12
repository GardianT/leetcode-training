func intToRoman(num int) string {
    roma_map := [][]string{
        {"", "M", "MM", "MMM"},
        {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"},
        {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"},
        {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"}}
    res := ""
    d := []int{1000, 100, 10, 1}
    
    for k, v := range(d) {
        res += roma_map[k][int(num / v)]
        num %= v
    }
    return res
}