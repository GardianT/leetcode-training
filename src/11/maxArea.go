func max(i, j int) int {
    if i > j {
        return i
    }
    return j
}

func min(i, j int) int {
    if i > j {
        return j
    }
    return i
}

func maxArea(height []int) int {
    left, right := 0, len(height) - 1
    res := 0
    for {
        if left == right {
            break
        }
        res = max(res, min(height[left], height[right]) * (right - left))
        if height[left] < height[right] {
            left++
        } else {
            right--
        }
    }
    return res
}