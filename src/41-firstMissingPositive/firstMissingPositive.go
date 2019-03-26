func firstMissingPositive(nums []int) int {
    for i := 0; i < len(nums); i++ {
        for {
            if 1 <= nums[i] && nums[i] <= len(nums) {
                swap_index := nums[i] - 1
                if nums[swap_index] != swap_index + 1 {
                    nums[i], nums[swap_index] = nums[swap_index], nums[i]
                } else {
                    break
                }
            } else {
                break
            }
        }
    }
    
    for i, val := range(nums) {
        if val != i + 1 {
            return i + 1
        }
    }
    return len(nums) + 1
}

