class Solution(object):
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        if len(prices) < 2:
            return 0
        profit = map(lambda x,y: y - x, prices[0:-1], prices[1:])
        profit.insert(0, 0)
        return reduce(lambda x,y: x + y if y > 0 else x, profit)