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