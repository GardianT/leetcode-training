#
# @lc app=leetcode.cn id=605 lang=python
#
# [605] 种花问题
#

# 贪心的方法，碰到连续三个0就可以种一个花
# 左右两边各加一个0，可以防边界问题
# @lc code=start
class Solution(object):
    def canPlaceFlowers(self, flowerbed, n):
        """
        :type flowerbed: List[int]
        :type n: int
        :rtype: bool
        """
        now_flowers = sum(flowerbed)
        flowerbed = [0] + flowerbed + [0]
        for i in range(1, len(flowerbed) - 1):
            if flowerbed[i - 1] == 0 and flowerbed[i] == 0 and flowerbed[i + 1] == 0:
                flowerbed[i] = 1
        return (sum(flowerbed) - now_flowers) >= n
# @lc code=end

