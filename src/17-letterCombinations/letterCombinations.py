nt = ['abc', 'def', 'ghi', 'jkl', 'mno', 'pqrs', 'tuv', 'wxyz']

def recurse(nt, res):
    if not nt:
        return res
    tmp_res = [''] if not res else res
    res = []
    for i in nt[0]:
        for j in tmp_res:
            res.append(j + i)
    nt.pop(0)
    return recurse(nt, res)
    

class Solution(object):
    
    
    def letterCombinations(self, digits):
        """
        :type digits: str
        :rtype: List[str]
        """
        target_nt = [nt[int(x) - 2] for x in digits]
        res = []
        return recurse(target_nt, res)