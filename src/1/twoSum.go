func twoSum(nums []int, target int) []int {
    index_map := make(map[int]int)
    for idx, val := range nums {
        if left_idx, ok := index_map[target - val]; ok {
            return []int{left_idx, idx}
        }
        index_map[val] = idx
    }
    return nil
}