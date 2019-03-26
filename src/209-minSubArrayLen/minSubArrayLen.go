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