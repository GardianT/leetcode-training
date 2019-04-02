# Q:
# 给定一个可包含重复数字的序列，返回所有不重复的全排列。
# 示例:
# 输入: [1,1,2]
# 输出:
# [
#   [1,1,2],
#   [1,2,1],
#   [2,1,1]
# ]

# 思路：46题返回一个set就可以了
import copy
def each_append(tmp, x):
    if not tmp:
        return [[x]]
    cp_tmp = copy.deepcopy(tmp)
    map(lambda i: i.append(x), cp_tmp)
    return cp_tmp


def recursive(candidates, tmp, ret):
    if not candidates:
        for i in tmp:
            if i not in ret:
                ret.append(i)
                
    for i in candidates:
        tmp_candidates = copy.deepcopy(candidates)
        tmp_candidates.remove(i)
        recursive(tmp_candidates, each_append(tmp, i), ret)
            

class Solution(object):
    def permuteUnique(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        # import itertools
        # return list(set(itertools.permutations(nums, len(nums))))
        ret = []
        recursive(nums, [], ret)
        return ret

        