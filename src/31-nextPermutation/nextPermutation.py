def swap(target, i, j):
    target[i], target[j] = target[j], target[i]

class Solution(object):
    def nextPermutation(self, nums):
        """
        :type nums: List[int]
        :rtype: None Do not return anything, modify nums in-place instead.
        """
        i = len(nums) - 2
        while i >= 0 and nums[i + 1] <= nums[i]:
            i -= 1
        if i >= 0:
            j = len(nums) - 1
            while j >= i and nums[j] <= nums[i]:
                j -= 1
            swap(nums, i, j)
        nums[i + 1:] = reversed(nums[i + 1:])       

# class Solution(object):
#     def nextPermutation(self, nums):
#         """
#         :type nums: List[int]
#         :rtype: None Do not return anything, modify nums in-place instead.
#         """
#         import itertools
#         permutations = sorted(set(itertools.permutations(nums)))
#         if tuple(nums) == permutations[-1]:
#             nums[:] = list(permutations[0])
#         else:
#             nums[:] = list(permutations[permutations.index(tuple(nums)) + 1])
        