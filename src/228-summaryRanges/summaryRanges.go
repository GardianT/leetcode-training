// Q:
// 给定一个无重复元素的有序整数数组，返回数组区间范围的汇总。
// 示例 1:
// 输入: [0,1,2,4,5,7]
// 输出: ["0->2","4->5","7"]
// 解释: 0,1,2 可组成一个连续的区间; 4,5 可组成一个连续的区间。
// 示例 2:
// 输入: [0,2,3,4,6,8,9]
// 输出: ["0","2->4","6","8->9"]
// 解释: 2,3,4 可组成一个连续的区间; 8,9 可组成一个连续的区间。

import "strconv"

func summaryRanges(nums []int) []string {
    res := []string{}
    if len(nums) == 0 {
        return res
    }
    
    for i, v := range nums {
        if i == 0 {
            res = append(res, strconv.Itoa(v))
        } else {
            if (v - nums[i - 1]) > 1 {
                lastv, _ := strconv.Atoi(res[len(res) - 1])
                if lastv != nums[i - 1] {
                    res[len(res) - 1] += "->" + strconv.Itoa(nums[i - 1]) 
                }
                res = append(res, strconv.Itoa(v))
            }
        }
    }
    lastv, _ := strconv.Atoi(res[len(res) - 1])
    if nums[len(nums) - 1] != lastv {
        res[len(res) - 1] += "->" + strconv.Itoa(nums[len(nums) - 1]) 
    }
    
    return res
}