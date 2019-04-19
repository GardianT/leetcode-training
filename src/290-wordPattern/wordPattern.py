# Q:
# 给定一种 pattern(模式) 和一个字符串 str ，判断 str 是否遵循相同的模式。
# 这里的遵循指完全匹配，例如， pattern 里的每个字母和字符串 str 中的每个非空单词之间存在着双向连接的对应模式。
# 示例1:
# 输入: pattern = "abba", str = "dog cat cat dog"
# 输出: true
# 示例 2:
# 输入:pattern = "abba", str = "dog cat cat fish"
# 输出: false

class Solution(object):
    def wordPattern(self, pattern, str):
        """
        :type pattern: str
        :type str: str
        :rtype: bool
        """
        mapp = {}
        if len(pattern) != len(str.split()):
            return False
        for i, v in enumerate(str.split()):
            if v not in mapp.keys():
                if pattern[i] not in mapp.values():
                    mapp[v] = pattern[i]
                else:
                    return False
            if mapp[v] != pattern[i]:
                return False
        return True
