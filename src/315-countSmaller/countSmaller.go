// Q:
// 给定一个整数数组 nums，按要求返回一个新数组 counts。数组 counts 有该性质： counts[i] 的值是  nums[i] 右侧小于 nums[i] 的元素的数量。
// 示例:
// 输入: [5,2,6,1]
// 输出: [2,1,1,0] 
// 解释:
// 5 的右侧有 2 个更小的元素 (2 和 1).
// 2 的右侧仅有 1 个更小的元素 (1).
// 6 的右侧有 1 个更小的元素 (1).
// 1 的右侧有 0 个更小的元素.
func countSmaller(nums []int) []int {
    res := []int{}
    nmap := map[int]int{}
    for i := len(nums) - 1; i > -1; i-- {
        resi := 0
        for k, v := range nmap {
            if k < nums[i] {
                resi += v
            }
        }
        res = append([]int{resi}, res...)
        if _, ok := nmap[nums[i]]; ok {
            nmap[nums[i]] += 1
        } else {
            nmap[nums[i]] = 1
        }
    }
    return res
}