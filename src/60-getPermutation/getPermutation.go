// Q：
// 给出集合 [1,2,3,…,n]，其所有元素共有 n! 种排列。
// 按大小顺序列出所有排列情况，并一一标记，当 n = 3 时, 所有排列如下：
// "123"
// "132"
// "213"
// "231"
// "312"
// "321"
// 给定 n 和 k，返回第 k 个排列。
// 说明：
// 给定 n 的范围是 [1, 9]。
// 给定 k 的范围是[1,  n!]。
// 示例 1:
// 输入: n = 3, k = 3
// 输出: "213"
// 示例 2:
// 输入: n = 4, k = 9
// 输出: "2314"

// 思路：
// 可以用数学的方法来解, 因为数字都是从1开始的连续自然数, 排列出现的次序可以推
// 算出来, 对于n=4, k=15 找到k=15排列的过程:
// 1 + 对2,3,4的全排列 (3!个)         
// 2 + 对1,3,4的全排列 (3!个)         3, 1 + 对2,4的全排列(2!个)
// 3 + 对1,2,4的全排列 (3!个)-------> 3, 2 + 对1,4的全排列(2!个)-------> 3, 2, 1 + 对4的全排列(1!个)-------> 3214
// 4 + 对1,2,3的全排列 (3!个)         3, 4 + 对1,2的全排列(2!个)         3, 2, 4 + 对1的全排列(1!个)
// 确定第一位:
//     k = 14(从0开始计数)
//     index = k / (n-1)! = 2, 说明第15个数的第一位是3 
//     更新k
//     k = k - index*(n-1)! = 2
// 确定第二位:
//     k = 2
//     index = k / (n-2)! = 1, 说明第15个数的第二位是2
//     更新k
//     k = k - index*(n-2)! = 0
// 确定第三位:
//     k = 0
//     index = k / (n-3)! = 0, 说明第15个数的第三位是1
//     更新k
//     k = k - index*(n-3)! = 0
// 确定第四位:
//     k = 0
//     index = k / (n-4)! = 0, 说明第15个数的第四位是4
// 最终确定n=4时第15个数为3214
import "strconv"

func getFactorial(n int) int {
    res := 1
    for i := 2; i <= n; i++ {
        res *= i
    }
    return res
}

func makeRange(min, max int) []int {
    res := make([]int, max - min + 1)
    for i := range res {
        res[i] = min + i
    }
    return res
}

func remove(target []int, i int) []int {
    return append(target[:i], target[i + 1:]...)
}

func getPermutation(n int, k int) string {
    rangeSlice := makeRange(1, n)
    res := ""
    for {
        if len(rangeSlice) == 0 {
            break
        } else if len(rangeSlice) == 1 {
            res += strconv.Itoa(rangeSlice[0])
            break
        } else {
            count := getFactorial(n - 1)
            i := (k - 1) / count 
            res += strconv.Itoa(rangeSlice[i])
            rangeSlice = remove(rangeSlice, i)
            k -= i * count
            n--
        }
    }
    return res
}