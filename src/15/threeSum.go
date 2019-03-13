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