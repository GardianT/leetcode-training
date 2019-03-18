func reverseSlice(target []int) {
    for i, j := 0, len(target) - 1; i < j; i, j = i+1, j-1 {
        target[i], target[j] = target[j], target[i]
    }
}

func nextPermutation(nums []int)  {
    i := len(nums) - 2
    for ; i >= 0; i-- {
        if nums[i + 1] > nums[i] {
            break
        }
    }
    if i >= 0 {
        j := len(nums) - 1
        for ; j >= i; {
            if nums[j] > nums[i] {
                break
            } else {
                j--
            }
        }
        nums[i], nums[j] = nums[j], nums[i]
    }
    reverseSlice(nums[i+1:])
}