def recursive(ln, rn, cur, res):
    if ln == 0 and rn == 1:
        res.append(cur + ")")
        return
    
    if ln > 0:
        recursive(ln-1, rn, cur + "(", res)
    
    if cur[-1] == '(':
        recursive(ln, rn - 1, cur + ')', res)
    elif rn > ln:
        recursive(ln, rn - 1, cur + ")", res)

class Solution(object):
    def generateParenthesis(self, n):
        """
        :type n: int
        :rtype: List[str]
        """
        res = []
        recursive(n-1, n, '(', res)
        return res
        