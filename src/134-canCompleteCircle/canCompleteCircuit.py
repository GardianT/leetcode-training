class Solution(object):
    def canCompleteCircuit(self, gas, cost):
        """
        :type gas: List[int]
        :type cost: List[int]
        :rtype: int
        """
        rest, run, start = 0, 0, 0
        for i in xrange(len(gas)):
            run += gas[i] - cost[i]
            rest += gas[i] - cost[i]
            if run < 0:
                start = i + 1
                run = 0
        return -1 if rest < 0 else start