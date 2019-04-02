# Q
# 一个机器人位于一个 m x n 网格的左上角 （起始点在下图中标记为“Start” ）。
# 机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为“Finish”）。
# 问总共有多少条不同的路径？
# 示例 1:
# 输入: m = 3, n = 2
# 输出: 3
# 解释:
# 从左上角开始，总共有 3 条路径可以到达右下角。
# 1. 向右 -> 向右 -> 向下
# 2. 向右 -> 向下 -> 向右
# 3. 向下 -> 向右 -> 向右
# 示例 2:
# 输入: m = 7, n = 3
# 输出: 28

# 思路：情况比较简单，直接排列组合即可求结果。
# 比如对于7， 3的情况。移动到右下角，需要 （7 - 1） +  （3 - 1） = 8步
# 8步里有 （3 - 1） 步是向下移动。也就是走8步，选取2步向下移动就行了。C82 = (8 * 7) / (2 * 1) = 28
# 第二种思路就是动态规划。到达i，j这个位置，可能是从i - 1, j这个位置向右移动来的，也可能是i，j - 1这个位置向下移动来的。
# f(i, j) = f(i - 1, j) + f（i， j -  1）
# 其中第一行和第一列都是1，因为只有一种走法。
class Solution(object):
    def uniquePaths(self, m, n):
        """
        :type m: int
        :type n: int
        :rtype: int
        """
        res = 1
        for i in range(1, n):
            res *= (m + n - 1 - i)
            res /= i
        return res