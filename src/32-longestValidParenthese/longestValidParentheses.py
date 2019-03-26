class Solution(object):
    def longestValidParentheses(self, s):
        """
        :type s: str
        :rtype: int
        """
        st, bitmap = [], [0] * len(s)
        for i, val in enumerate(s):
            if val == '(':
                st.append(i)
            elif st:
                bitmap[st.pop()], bitmap[i] = 1, 1
        
        tmp, res = 0, 0
        for i in bitmap:
            if i:
                tmp += 1
            else:
                res = max(tmp, res)
                tmp = 0
        return max(res, tmp)