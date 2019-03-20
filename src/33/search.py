def search(nums, left, right, target):
    if left > right:
        return -1
    if nums[left] == target:
        return left
    elif nums[right] == target:
        return right
    
    mid = (left + right) / 2
    if nums[mid] == target:
        return mid
    
    if nums[mid] < nums[right]:
        if nums[mid] < target and target < nums[right]:
            return search(nums, mid + 1, right, target)
        else:
            return search(nums, left, mid - 1, target)
    else:
        if nums[mid] > target and target > nums[left]:
            return search(nums, left, mid - 1, target)
        else:
            return search(nums, mid + 1, right, target)
    
    

class Solution(object):
    def search(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        return search(nums, 0, len(nums) - 1, target)