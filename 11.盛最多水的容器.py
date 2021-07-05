#
# @lc app=leetcode.cn id=11 lang=python
#
# [11] 盛最多水的容器
#

# 思路：双指针，然后每次让短的板子往里面移动。
# @lc code=start
class Solution(object):
    def maxArea(self, height):
        """
        :type height: List[int]
        :rtype: int
        """
        l, r = 0, len(height) - 1
        res = 0
        while l < r:
            cur = min(height[l], height[r]) * (r - l)
            res = max(cur, res)
            if height[l] < height[r]:
                l += 1
            else:
                r -= 1
        return res
# @lc code=end

