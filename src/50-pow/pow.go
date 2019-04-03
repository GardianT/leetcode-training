// Q：
// 实现 pow(x, n) ，即计算 x 的 n 次幂函数。
// 示例 1:
// 输入: 2.00000, 10
// 输出: 1024.00000
// 示例 2:
// 输入: 2.10000, 3
// 输出: 9.26100
// 示例 3:
// 输入: 2.00000, -2
// 输出: 0.25000
// 解释: 2-2 = 1/22 = 1/4 = 0.25

// 思路：类似更相减损的操作
func abs(x int) int {
    if x < 0 {
        return -x
    }
    return x
}

func myPow(x float64, n int) float64 {
    res := 1.0
    an := abs(n)
    for {
        if an != 0 {
            if an % 2 != 0 {
                res *= x
            }
            x *= x
            an /= 2
        } else {
            break
        }
    }
    
    if n < 0 {
        return 1.0 / res
    }
    return res
}