#
# @lc app=leetcode.cn id=88 lang=python
#
# [88] 合并两个有序数组
#

# 从后往前做归并就行
# @lc code=start
class Solution(object):
    def merge(self, nums1, m, nums2, n):
        """
        :type nums1: List[int]
        :type m: int
        :type nums2: List[int]
        :type n: int
        :rtype: None Do not return anything, modify nums1 in-place instead.
        """
        cur = len(nums1) - 1
        l1, l2 = m - 1, n - 1
        while l1 >= 0 and l2 >= 0:
            if nums1[l1] > nums2[l2]:
                nums1[cur] = nums1[l1]
                l1 -= 1
            else:
                nums1[cur] = nums2[l2]
                l2 -= 1
            cur -= 1
        while l2 >= 0:
            nums1[cur] = nums2[l2]
            cur -= 1
            l2 -= 1

# @lc code=end

