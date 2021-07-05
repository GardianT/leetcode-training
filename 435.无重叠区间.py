#
# @lc app=leetcode.cn id=435 lang=python
#
# [435] 无重叠区间
#

# 贪心方法，按照右边界排序，如果相交就剔除
# @lc code=start
class Solution(object):
    def eraseOverlapIntervals(self, intervals):
        """
        :type intervals: List[List[int]]
        :rtype: int
        """
        res = 0
        if len(intervals) == 0:
            return res
        intervals.sort(key=lambda x: x[1])
        right_bound = intervals[0][1]
        for i in range(1, len(intervals)):
            if intervals[i][0] >= right_bound:
                right_bound = intervals[i][1]
            else:
                res += 1
        return res
# @lc code=end

