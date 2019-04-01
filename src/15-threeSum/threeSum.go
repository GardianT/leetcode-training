// Q:
// 给定一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0 ？找出所有满足条件且不重复的三元组。
// 注意：答案中不可以包含重复的三元组。
// 例如, 给定数组 nums = [-1, 0, 1, 2, -1, -4]，
// 满足要求的三元组集合为：
// [
//   [-1, 0, 1],
//   [-1, -1, 2]
// ]

// 思路：sort后双指针。
import "sort"

func contains(containers [][]int, target []int) bool {
    for _, tmp := range(containers) {
        if len(tmp) != len(target) {
            continue
        }

        matched := true
        for i := 0; i < len(tmp); i++ {
            if tmp[i] != target[i] {
                matched = false
            }
            if !matched {
                break
            }
        }
        
        if matched {
            return true
        }
    }
    return false
}

func threeSum(nums []int) [][]int {
    sort.Ints(nums)
    
    res := [][]int{}
    
    for i := 0; i < len(nums) - 2; i++ {
        j, k := i + 1, len(nums) - 1
        for {
            if j >= k {
                break
            }
            tmpval := nums[j] + nums[k]
            if tmpval == -nums[i] {
                tmpres := []int{nums[i], nums[j], nums[k]}
                if !contains(res, tmpres) {
                    res = append(res, tmpres) 
                }
                j++
            } else if tmpval > -nums[i] {
                k--
            } else {
                j++
            }
        }
    }
    
    return res
}