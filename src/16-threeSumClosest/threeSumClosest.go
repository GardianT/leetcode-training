// Q：
// 给定一个包括 n 个整数的数组 nums 和 一个目标值 target。找出 nums 中的三个整数，使得它们的和与 target 最接近。返回这三个数的和。假定每组输入只存在唯一答案。
// 例如，给定数组 nums = [-1，2，1，-4], 和 target = 1.
// 与 target 最接近的三个数的和为 2. (-1 + 2 + 1 = 2).

// 思路：跟15题一样。
import (
    "sort"
    "math"
)

func threeSumClosest(nums []int, target int) int {
    sort.Ints(nums)
    closetSum := 1 << 31
    for i := 0; i < len(nums) - 2; i++ {
        j, k := i+1, len(nums) - 1
        for {
            if j >= k {
                break
            }
            cur_sum := nums[i] + nums[j] + nums[k]
            if cur_sum == target {
                return target
            }
            if math.Abs(float64(cur_sum - target)) < math.Abs(float64(closetSum - target)) {
                closetSum = cur_sum
            }
            if cur_sum > target {
                k--
            } else {
                j++
            }
        }
    }
    return closetSum
}