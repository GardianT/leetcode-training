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