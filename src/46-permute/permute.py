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