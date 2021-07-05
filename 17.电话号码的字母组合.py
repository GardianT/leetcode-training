#
# @lc app=leetcode.cn id=17 lang=python
#
# [17] 电话号码的字母组合
#

# @lc code=start
class Solution(object):
    def letterCombinations(self, digits):
        """
        :type digits: str
        :rtype: List[str]
        """
        
        def foo(cur, res):
            if len(cur) == 0:
                return res
            nt = ['abc', 'def', 'ghi', 'jkl', 'mno', 'pqrs', 'tuv', 'wxyz']
            chrs = nt[int(cur[0]) - 2]
            if len(res) == 0:
                for i in chrs:
                    res.append(i)
            else:
                tmp = []
                for i in chrs:
                    for ii in res:
                        tmp.append(ii + i)
                res = tmp
            return foo(cur[1:], res)
        return foo(digits, [])


# @lc code=end

