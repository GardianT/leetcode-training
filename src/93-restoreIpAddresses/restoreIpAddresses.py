# Q:
# 给定一个只包含数字的字符串，复原它并返回所有可能的 IP 地址格式。
# 示例:
# 输入: "25525511135"
# 输出: ["255.255.11.135", "255.255.111.35"]

# 思路：dfs
def dfs(s, path, res):
    if not s and len(path) == 4:
        res.append('.'.join(path))
        return
    
    for i in range(1, 4):
        if i > len(s):
            continue
        ip_num = int(s[:i])
        # 避免0开头
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