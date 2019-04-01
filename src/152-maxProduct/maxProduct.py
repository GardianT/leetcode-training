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