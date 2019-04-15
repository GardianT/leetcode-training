// Q:
// 给定一个大小为 n 的数组，找出其中所有出现超过 ⌊ n/3 ⌋ 次的元素。
// 说明: 要求算法的时间复杂度为 O(n)，空间复杂度为 O(1)。
// 示例 1:
// 输入: [3,2,3]
// 输出: [3]
// 示例 2:
// 输入: [1,1,1,3,3,2,2,2]
// 输出: [1,2]

// 思路：
// 超过数组二分之一长度的数字，最多只会有一个，用一个变量标记即可
// 同理，超过数组长度三分之一的数字，最多只会有两个，用两个变量标记即可
func majorityElement(nums []int) []int {
    res := []int{}
    x, y, cx, cy := 0, 0, 0, 0
    for _, v := range nums {
        if (cx == 0 || v == x) && v != y {
            cx++
            x = v
        } else if (cy == 0 || v == y) {
            cy++
            y = v
        } else {
            cx--
            cy--
        }
    }
    c1, c2 := 0, 0 
    for _, v := range nums {
        if v == x {
            c1++
        } else if v == y {
            c2++
        }
    }
    if c1 > len(nums) / 3 {
        res = append(res, x)
    }
    if c2 > len(nums) / 3 && x != y {
        res = append(res, y)
    }
    return res
}