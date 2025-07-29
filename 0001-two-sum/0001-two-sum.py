class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        mp = {}
        for i in range(0,len(nums)):
            if target-nums[i] in mp:
                return [mp[target-nums[i]],i]
            mp[nums[i]] = i
        return []
        