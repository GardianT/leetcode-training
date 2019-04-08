// Q：
// 给定一组非负整数，重新排列它们的顺序使之组成一个最大的整数。
// 示例 1:
// 输入: [10,2]
// 输出: 210
// 示例 2:
// 输入: [3,30,34,5,9]
// 输出: 9534330
// 说明: 输出结果可能非常大，所以你需要返回一个字符串而不是整数。

// 思路：重定义排序方法即可
import (
    "sort"
    "strconv"
)
func largestNumber(nums []int) string {
    sort.Slice(nums, func(i, j int) bool {
        return strconv.Itoa(nums[i]) + strconv.Itoa(nums[j]) > strconv.Itoa(nums[j]) + strconv.Itoa(nums[i])
    })
    res := ""
    for _, val := range nums {
        res += strconv.Itoa(val)
    }
    int_res, _ := strconv.Atoi(res)
    if int_res == 0 {
        return "0"
    }
    return res
}