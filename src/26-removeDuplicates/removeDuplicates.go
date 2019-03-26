func removeDuplicates(nums []int) int {
    newlen := 0
    for i := 1; i < len(nums); i++ {
        if nums[i] != nums[newlen] {
            newlen++
            nums[newlen] = nums[i]
        }
    }
    return newlen + 1
}