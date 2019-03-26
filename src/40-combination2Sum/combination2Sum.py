def recursive(candidates, cur, target, res):
    if target == 0:
        if sorted(cur) not in res:
            res.append(sorted(cur))
    
    for i in candidates:
        tmp_candidates = candidates[:]
        if i <= target:
            tmp_candidates.remove(i)
            recursive(tmp_candidates, cur + [i], target - i, res)

class Solution(object):
    def combinationSum2(self, candidates, target):
        """
        :type candidates: List[int]
        :type target: int
        :rtype: List[List[int]]
        """
        res = []
        recursive(candidates, [], target, res)
        return res
        