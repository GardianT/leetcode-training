class Solution(object):
    def mySqrt(self, x):
        """
        :type x: int
        :rtype: int
        https://en.wikipedia.org/wiki/Integer_square_root#Using_only_integer_division
        """
        if x <= 1:
            return x
        res = x
        while res > x / res:
            res = (res + x / res) / 2
        return int(res)