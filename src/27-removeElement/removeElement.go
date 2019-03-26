func removeElement(nums []int, val int) int {
    i, n := 0, len(nums)
    for {
        if i >= n {
            break
        }
        if nums[i] == val {
            nums[i] = nums[n - 1]
            n--
        } else {
            i++
        }
    }
    return n
}