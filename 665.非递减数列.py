#
# @lc app=leetcode.cn id=665 lang=python
#
# [665] 非递减数列
#

# 贪心策略：如果i+1 < i， 判断i-1 和 i+1 的关系
# 如果i-1 > i+1, 需要把i+1调大，如果 i-1 < i+1，把i调小
# @lc code=start
class Solution(object):
    def checkPossibility(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        arr = [-9999999] + nums
        
        for i in range(len(arr) - 1):
            if arr[i + 1] < arr[i]:
                if arr[i - 1] > arr[i + 1]:
                    arr[i+1] = arr[i]
                else:
                    arr[i] = arr[i - 1]
                break
                
        for i in range(len(arr) - 1):
            if arr[i + 1] < arr[i]:
                return False
        return True
# @lc code=end

