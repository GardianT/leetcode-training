func romanToInt(s string) int {
    roma_map := map[string]int{
        "I": 1,
        "V": 5,
        "X": 10,
        "L": 50,
        "C": 100,
        "D": 500,
        "M": 1000}
    
    last_val := roma_map[string(s[0])]
    res := 0
    for _, chr := range s {
        var cur_val int = roma_map[string(chr)]
        res += cur_val
        if cur_val > last_val {
            res -= 2 * last_val    
        }
        last_val = cur_val
    }
    return res
}