# Q:
# 给定一个包含 n + 1 个整数的数组 nums，其数字都在 1 到 n 之间（包括 1 和 n），可知至少存在一个重复的整数。假设只有一个重复的整数，找出这个重复的数。
# 示例 1:
# 输入: [1,3,4,2,2]
# 输出: 2

# 思路：如果nums[i] 不等于 i+1，就把nums[i] 换到它正确的位置上
# 如果发现nums[i]所在的位置，已经被占据了，就说明找到重复数字了
class Solution(object):
    def findDuplicate(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        i = 0
        while i < len(nums):
            while nums[i] != i + 1:
                if nums[nums[i] - 1] != nums[i]:
                    tmp = nums[i]
                    nums[i] = nums[nums[i] - 1]
                    nums[tmp - 1] = tmp
                else:
                    return nums[i]
            i += 1
        return 0
