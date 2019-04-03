// Q:
// 给定一个含有 n 个正整数的数组和一个正整数 s ，找出该数组中满足其和 ≥ s 的长度最小的连续子数组。如果不存在符合条件的连续子数组，返回 0。
// 示例: 
// 输入: s = 7, nums = [2,3,1,2,4,3]
// 输出: 2
// 解释: 子数组 [4,3] 是该条件下的长度最小的连续子数组。

// 思路：双指针
func min(x, y int) int {
    if x > y {
        return y
    }
    return x
}

func minSubArrayLen(s int, nums []int) int {
    if len(nums) == 0 {
        return 0
    }
    left, right, res, sum := 0, -1, len(nums) + 1, 0
    for {
        if left == len(nums) {
            break
        }
        if sum < s && (right + 1) < len(nums) {
            right++
            sum += nums[right]
        } else {
            sum -= nums[left]
            left++
        }
        
        if sum >= s {
            res = min(res, right - left + 1)
        }
    }
    if res == len(nums) + 1 {
        return 0
    }
    return res
}