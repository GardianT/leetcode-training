// Q：
// 给定两个整数，被除数 dividend 和除数 divisor。将两数相除，要求不使用乘法、除法和 mod 运算符。
// 返回被除数 dividend 除以除数 divisor 得到的商。
// 示例 1:
// 输入: dividend = 10, divisor = 3
// 输出: 3
// 示例 2:
// 输入: dividend = 7, divisor = -3
// 输出: -2

// 网上看的思路，位运算
func min(x, y int) int {
    if x > y {
        return y
    }
    return x
}

func abs(x int) int {
    if x < 0 {
        return -x
    }
    return x
}

func divide(dividend int, divisor int) int {
    abs_v, abs_d := abs(dividend), abs(divisor)
    if dividend == 0 || abs_v < abs_d {
        return 0
    }
    
    i, res := 0, 0
    for {
        if (abs_d << uint64(i)) <= abs_v {
            i++
        } else {
            break
        }
    }
    
    for j := i - 1; j >= 0; j-- {
        if (abs_d << uint64(j)) <= abs_v {
            abs_v -= (abs_d << uint64(j))
            res += (1 << uint64(j))
        }
    }
    if dividend ^ divisor < 0 {
        res = -res
    }
    return min(res, (1 << 31) - 1)
}