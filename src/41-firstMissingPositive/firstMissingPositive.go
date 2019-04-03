// Q：
// 给定一个未排序的整数数组，找出其中没有出现的最小的正整数。
// 示例 1:
// 输入: [1,2,0]
// 输出: 3
// 示例 2:
// 输入: [3,4,-1,1]
// 输出: 2
// 示例 3:
// 输入: [7,8,9,11,12]
// 输出: 1
// 说明:
// 你的算法的时间复杂度应为O(n)，并且只能使用常数级别的空间。

// 思路：从头到尾遍历，把所有的数字放到正确的位置上。（这个过程是个while，就是一直找到了正确的数字为止）
// 然后第二遍遍历，位置上数字不准确的，就是没有出现的数字。
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

