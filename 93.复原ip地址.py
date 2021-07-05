#
# @lc app=leetcode.cn id=93 lang=python
#
# [93] 复原IP地址
#

# @lc code=start
class Solution(object):
    def restoreIpAddresses(self, s):
        """
        :type s: str
        :rtype: List[str]
        """
        if len(s) > 12 or len(s) < 3:
            return []
        
        res = []
        def dfs(left, path):
            if len(path) == 4:
                if not left:
                    ip = '.'.join(path)
                    if ip not in res:
                        res.append(ip)
                return

            for i in range(3):
                if i >= len(left):
                    return
                substr = left[:i+1]
                intcur = int(substr)
                if str(intcur) == substr and intcur <= 255:
                    dfs(left[i+1:], path + [substr])
        dfs(s, [])
        return res 
# @lc code=end

