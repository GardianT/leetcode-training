#
# @lc app=leetcode.cn id=452 lang=python
#
# [452] 用最少数量的箭引爆气球
#

# 贪心：先排序右边界再排序左边界，然后遍历气球，如果当前气球不跟前面所有气球的右边界相交
# 那就说明前面已经是最大重叠的气球了，需要清除。
# 用排序优化下，可得知不用遍历前面所有的气球，只要前面剩下的第一个气球就好了

# @lc code=start
class Solution(object):
    def findMinArrowShots(self, points):
        """
        :type points: List[List[int]]
        :rtype: int
        """
        if len(points) == 0:
            return 0
        points.sort(key = lambda x: (x[1], x[0]))
        last_idx, res = 0, 0
        for i, point in enumerate(points):
            if last_idx != i:
                if points[last_idx][1] < points[i][0]:
                    res += 1
                    last_idx = i
        return res + 1
# @lc code=end

