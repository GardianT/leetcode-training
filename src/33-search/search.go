// Q：
// 假设按照升序排序的数组在预先未知的某个点上进行了旋转。
// ( 例如，数组 [0,1,2,4,5,6,7] 可能变为 [4,5,6,7,0,1,2] )。
// 搜索一个给定的目标值，如果数组中存在这个目标值，则返回它的索引，否则返回 -1 。
// 你可以假设数组中不存在重复的元素。
// 你的算法时间复杂度必须是 O(log n) 级别。
// 示例 1:
// 输入: nums = [4,5,6,7,0,1,2], target = 0
// 输出: 4
// 示例 2:
// 输入: nums = [4,5,6,7,0,1,2], target = 3
// 输出: -1

// 思路：二分，难点在边界判断。
func Search(nums []int, left, right, target int) int {
    if left > right {
        return -1
    }
    
    if nums[left] == target {
        return left
    } else if nums[right] == target {
        return right
    }
    
    mid := (left + right) / 2
    if nums[mid] == target {
        return mid
    } else if nums[mid] < nums[right] {
        if nums[mid] < target && target < nums[right] {
            return Search(nums, mid + 1, right, target)
        } else {
            return Search(nums, left, mid - 1, target)
        }
    } else {
        if nums[left] < target && target < nums[mid] {
            return Search(nums, left, mid - 1, target)
        } else {
            return Search(nums, mid + 1, right, target)
        }
    }
}

func search(nums []int, target int) int {
    return Search(nums, 0, len(nums) - 1, target)
}