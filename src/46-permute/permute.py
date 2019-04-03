# Q:
# 给定一个没有重复数字的序列，返回其所有可能的全排列。
# 示例:
# 输入: [1,2,3]
# 输出:
# [
#   [1,2,3],
#   [1,3,2],
#   [2,1,3],
#   [2,3,1],
#   [3,1,2],
#   [3,2,1]
# ]

# 思路：递归就可以了
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
    def permute(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        # import itertools
        # return list(itertools.permutations(nums, len(nums)))

        ret = []
        recursive(nums, [], ret)
        return ret