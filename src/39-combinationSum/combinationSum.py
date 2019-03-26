def recursive(candite, cur, target, res):
    if target == 0:
        if sorted(cur) not in res:
            res.append(sorted(cur))
    
    for i in candite:
        if i <= target:
            recursive(candite, cur + [i], target - i, res)

class Solution(object):
    def combinationSum(self, candidates, target):
        """
        :type candidates: List[int]
        :type target: int
        :rtype: List[List[int]]
        """
        res = []
        recursive(candidates, [], target, res)
        return res