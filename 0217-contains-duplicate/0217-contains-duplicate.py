class Solution(object):
    def containsDuplicate(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        mp = {}
        for i in range(0,len(nums)):
            if nums[i] in mp:
                return True
            mp[nums[i]]=1
        return False
        