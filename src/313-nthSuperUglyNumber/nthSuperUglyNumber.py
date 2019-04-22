# Q:
# 编写一段程序来查找第 n 个超级丑数。
# 超级丑数是指其所有质因数都是长度为 k 的质数列表 primes 中的正整数。
# 示例:
# 输入: n = 12, primes = [2,7,13,19]
# 输出: 32 
# 解释: 给定长度为 4 的质数列表 primes = [2,7,13,19]，前 12 个超级丑数序列为：[1,2,4,7,8,13,14,16,19,26,28,32] 
class Solution(object):
    def nthSuperUglyNumber(self, n, primes):
        """
        :type n: int
        :type primes: List[int]
        :rtype: int
        """
        if n == 1:
            return 1
        idxs = [0 for i in xrange(len(primes))]
        res = [1]
        for i in range(1, n):
            candidates = map(lambda x,y: res[x]*y, idxs, primes)
            val = 0
            if len(candidates) == 1:
                val = candidates[0]
            else:
                val = min(*candidates)
            res.append(val)
            for i, v in enumerate(candidates):
                if v == val:
                    idxs[i] += 1
        return res[-1]