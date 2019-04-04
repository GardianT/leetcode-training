# Q:
# 峰值元素是指其值大于左右相邻值的元素。
# 给定一个输入数组 nums，其中 nums[i] ≠ nums[i+1]，找到峰值元素并返回其索引。
# 数组可能包含多个峰值，在这种情况下，返回任何一个峰值所在位置即可。
# 你可以假设 nums[-1] = nums[n] = -∞。
# 示例 1:
# 输入: nums = [1,2,3,1]
# 输出: 2
# 解释: 3 是峰值元素，你的函数应该返回其索引 2。
# 示例 2:
# 输入: nums = [1,2,1,3,5,6,4]
# 输出: 1 或 5 
# 解释: 你的函数可以返回索引 1，其峰值元素为 2；
#      或者返回索引 5， 其峰值元素为 6。
# 说明:
# 你的解法应该是 O(logN) 时间复杂度的。

# 思路：硬上二分
# 二分核心不在数组有序，而是缩小查找范围。
# 每次找中点。中点和它左右两边的数字进行比较
# 如果中点比左边的数小，说明左边范围内可能存在peak
# 如果中点比右边数小，说明右边范围内可能存在peak
# 否则中点就是peak
class Solution(object):
    def findPeakElement(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if not nums or len(nums) < 1:
            return -1
        if len(nums) < 2:
            nums.append(float('-inf'))
        
        left, right = 0, len(nums) - 1
        while left + 1 < right:
            mid = left + (right - left) / 2
            if nums[mid - 1] > nums[mid]:
                right = mid
            elif nums[mid + 1] > nums[mid]:
                left = mid
            else:
                return mid
            
        if nums[left] > nums[right]:
            return left
        return right