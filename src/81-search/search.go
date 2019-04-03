// Q：
// 假设按照升序排序的数组在预先未知的某个点上进行了旋转。
// ( 例如，数组 [0,0,1,2,2,5,6] 可能变为 [2,5,6,0,0,1,2] )。
// 编写一个函数来判断给定的目标值是否存在于数组中。若存在返回 true，否则返回 false。
// 示例 1:
// 输入: nums = [2,5,6,0,0,1,2], target = 0
// 输出: true
// 示例 2:
// 输入: nums = [2,5,6,0,0,1,2], target = 3
// 输出: false

// 思路：二分
func Search(nums []int, left, right, target int) bool {
    if left > right {
        return false
    }
    
    if nums[left] == nums[right] {
        for _, v := range nums {
            if v == target {
                return true
            }
        }
        return false
    }
    
    if nums[left] == target {
        return true
    } else if nums[right] == target {
        return true
    }
    
    mid := (left + right) / 2
    if nums[mid] == target {
        return true
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

func search(nums []int, target int) bool {
    return Search(nums, 0, len(nums) - 1, target)
}

