def dfs(s, path, res):
    if not s and len(path) == 4:
        res.append('.'.join(path))
        return
    
    for i in range(1, 4):
        if i > len(s):
            continue
        ip_num = int(s[:i])
        if str(ip_num) == s[:i] and ip_num <= 255:
            dfs(s[i:], path + [s[:i]], res)


class Solution(object):
    def restoreIpAddresses(self, s):
        """
        :type s: str
        :rtype: List[str]
        """
        if len(s) > 12:
            return []
        res = []
        dfs(s, [], res)
        return res