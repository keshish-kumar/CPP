class Solution(object):
    def missingNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        l = len(nums)
        ans= l
        for i in range(0,l):
            ans = ans^nums[i]^i
        return ans
        