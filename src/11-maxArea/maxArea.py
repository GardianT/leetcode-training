class Solution(object):
    def maxArea(self, height):
        """
        :type height: List[int]
        :rtype: int
        """
        left, right = 0, len(height) - 1
        maxarea = 0
        while left < right:
            maxarea = max(min(height[left], height[right]) * (right - left), maxarea)
            if height[left] > height[right]:
                right -= 1
            else:
                left += 1
        return maxarea