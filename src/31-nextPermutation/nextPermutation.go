// Q：
// 实现获取下一个排列的函数，算法需要将给定数字序列重新排列成字典序中下一个更大的排列。
// 如果不存在下一个更大的排列，则将数字重新排列成最小的排列（即升序排列）。
// 必须原地修改，只允许使用额外常数空间。
// 以下是一些例子，输入位于左侧列，其相应输出位于右侧列。
// 1,2,3 → 1,3,2
// 3,2,1 → 1,2,3
// 1,1,5 → 1,5,1

// 思路：从右到左，找第一个破坏了递增关系的那个数字。
// 比如， 12432， 从右到左，4和2破坏了递增关系
// 然后找这个2右边的所有数字（4，3，2），第一个比它大的数字，进行交换
// 也就是  3和2进行交换，13422
// 然后把这个位置后面的数字，从大到小进行排序，就是 13224
func reverseSlice(target []int) {
    for i, j := 0, len(target) - 1; i < j; i, j = i+1, j-1 {
        target[i], target[j] = target[j], target[i]
    }
}

func nextPermutation(nums []int)  {
    i := len(nums) - 2
    for ; i >= 0; i-- {
        if nums[i + 1] > nums[i] {
            break
        }
    }
    if i >= 0 {
        j := len(nums) - 1
        for ; j >= i; {
            if nums[j] > nums[i] {
                break
            } else {
                j--
            }
        }
        nums[i], nums[j] = nums[j], nums[i]
    }
    reverseSlice(nums[i+1:])
}