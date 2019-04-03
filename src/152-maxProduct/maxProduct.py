# Q:
# 给定个整数数组 nums ，找出一个序列中乘积最大的连续子序列（该序列至少包含一个数）。
# 示例 1:
# 输入: [2,3,-2,4]
# 输出: 6
# 解释: 子数组 [2,3] 有最大乘积 6。
# 示例 2:
# 输入: [-2,0,-1]
# 输出: 0
# 解释: 结果不能为 2, 因为 [-2,-1] 不是子数组。
class Solution(object):
    def maxProduct(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        ret, posMax, negMax = nums[0], nums[0], nums[0]
        for i in xrange(1, len(nums)):
            tmp1, tmp2 = posMax, negMax
            posMax = max(nums[i], max(nums[i] * tmp1, nums[i] * tmp2))
            negMax = min(nums[i], min(nums[i] * tmp1, nums[i] * tmp2))
            ret = max(ret, posMax)
        return ret