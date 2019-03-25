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

