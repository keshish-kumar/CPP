class Solution(object):
    def findMaxConsecutiveOnes(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        ans = 0
        temp=0
        for i in nums:
            if i==1:
                ans+=1
            else:
                ans=0
            temp = max(ans,temp)
        return temp
        