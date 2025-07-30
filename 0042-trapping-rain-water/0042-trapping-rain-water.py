class Solution(object):
    def trap(self, height):
        """
        :type height: List[int]
        :rtype: int
        """
        left = []
        right = []
        maxi = 0
        for i in range(0,len(height)):
            maxi = max(maxi,height[i])
            left.append(maxi)
        maxi = 0
        for i in range(len(height)-1,-1,-1):
            maxi = max(maxi,height[i])
            right.append(maxi)
        right.reverse()
        ans =0
        for i in range(0,len(height)):
            ans += min(left[i],right[i])-height[i]
        return ans

        