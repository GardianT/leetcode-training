#
# @lc app=leetcode.cn id=167 lang=python
#
# [167] 两数之和 II - 输入有序数组
#

# @lc code=start
class Solution(object):
    def twoSum(self, numbers, target):
        """
        :type numbers: List[int]
        :type target: int
        :rtype: List[int]
        """
        l, r = 0, len(numbers) - 1
        while l < r:
            cur = numbers[l] + numbers[r]
            if cur == target:
                break;
            elif cur > target:
                r -= 1
            elif cur < target:
                l += 1
        return [l + 1, r + 1]
# @lc code=end

