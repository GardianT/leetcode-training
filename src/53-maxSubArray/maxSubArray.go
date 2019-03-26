func max(i, j int) int {
    if i > j {
        return i
    }
    return j
}

func maxSubArray(nums []int) int {
    res, tmp := nums[0], 0
    for _, val := range(nums) {
        if tmp > 0 {
            tmp += val
        } else {
            tmp = val
        }
        res = max(tmp, res)
    }
    return res
}
