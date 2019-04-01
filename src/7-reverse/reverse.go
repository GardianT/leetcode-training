// Q
// 给出一个 32 位的有符号整数，你需要将这个整数中每位上的数字进行反转。
// 示例 1:
// 输入: 123
// 输出: 321
// 示例 2:
// 输入: -123
// 输出: -321
// 示例 3:
// 输入: 120
// 输出: 21

import "strconv"

func Reverse(s string) []rune {
    r := []rune(s)
    for i, j := 0, len(r)-1; i < len(r)/2; i, j = i+1, j-1 {
        r[i], r[j] = r[j], r[i]
    }
    return r
}

func reverse(x int) int {
    if x == 0 {
        return x
    }
    x_str := strconv.Itoa(x)
    reverse_str := Reverse(x_str)
    i := 0

    for _, ch := range(reverse_str) {
        if string(ch) == "0" {
            i++
        } else {
            break
        }
    }
    last_idx := len(reverse_str) - 1 
    res_list := []rune{}
    var res_str string
    if string(reverse_str[last_idx]) == "-" {
        res_list = reverse_str[i:last_idx]
        res_str = "-"
        res_str += string(res_list)
    } else {
        res_list = reverse_str[i:]
        res_str = string(res_list)
    }
    res, _ := strconv.Atoi(res_str)
    if -(1 << 31) < res && res < (1 << 31) - 1 {
        return res
    }
    return 0
}