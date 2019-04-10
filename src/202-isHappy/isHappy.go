// Q:
// 编写一个算法来判断一个数是不是“快乐数”。
// 一个“快乐数”定义为：对于一个正整数，每一次将该数替换为它每个位置上的数字的平方和，然后重复这个过程直到这个数变为 1，也可能是无限循环但始终变不到 1。如果可以变为 1，那么这个数就是快乐数。
// 示例: 
// 输入: 19
// 输出: true
// 解释: 
// 12 + 92 = 82
// 82 + 22 = 68
// 62 + 82 = 100
// 12 + 02 + 02 = 1
import "strconv"

func contains(nums []int, target int) bool {
    for _, v := range nums {
        if target == v {
            return true
        }
    }
    return false
}

func recursive(n int, occurs *[]int) bool {
    powsum := 0
    strn := strconv.Itoa(n)
    for _, v := range strn {
        bit, _ := strconv.Atoi(string(v))
        powsum += bit * bit
    }
    if powsum == 1 {
        return true
    } else if contains(*occurs, powsum) {
		// 循环就不会快乐了
		return false
    }
    *occurs = append(*occurs, powsum)
    return recursive(powsum, occurs)
}

func isHappy(n int) bool {
    if n == 0 {
        return false
    }
    if n == 1 {
        return true
    }
    return recursive(n, &[]int{})
}