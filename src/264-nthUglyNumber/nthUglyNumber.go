// 编写一个程序，找出第 n 个丑数。
// 丑数就是只包含质因数 2, 3, 5 的正整数。
// 示例:
// 输入: n = 10
// 输出: 12
// 解释: 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 是前 10 个丑数。

// 思路：三指针，分别指向上一次取min的位置。
import "math"
func min(nums ...int) int {
    res := math.MaxInt64
    for _, v := range nums {
        if v < res {
            res = v
        }
    }
    return res
}

func nthUglyNumber(n int) int {
    res := []int{1}
    idx1, idx2, idx3, next := 0, 0, 0, 0
    for i := 0; i < n - 1; i++ {
        n1, n2, n3 := res[idx1] * 2, res[idx2] * 3, res[idx3] * 5
        next = min(n1, n2, n3)
        res = append(res, next)
        if next == n1 {
            idx1++
        }
        if next == n2 {
            idx2++
        }
        if next == n3 {
            idx3++
        }
    }
    return res[len(res) - 1]
}