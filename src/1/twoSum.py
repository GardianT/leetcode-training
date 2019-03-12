class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        sum_map = {}
        for index, num in enumerate(nums):
            left = target - num
            if left in sum_map:
                return [sum_map[left], index]
            sum_map[num] = index
        return None