// Q：
// 给定一个整数数组 nums ，找到一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。
// 示例:
// 输入: [-2,1,-3,4,-1,2,1,-5,4],
// 输出: 6
// 解释: 连续子数组 [4,-1,2,1] 的和最大，为 6。

// 思路：动态规划。从头往后累加。如果累加的和大于0，则前面的队列对于累加有益。否则无益于累加。
// 方程就是
// f(n) = f(n - 1) + nums[n] if f(n - 1) > 0 else nums[n]
func max(i, j int) int {
    if i > j {
        return i
    }
    return j
}

func maxSubArray(nums []int) int {
    res, tmp := nums[0], 0
    for _, val := range(nums) {
        if tmp > 0 {
            tmp += val
        } else {
            tmp = val
        }
        res = max(tmp, res)
    }
    return res
}
