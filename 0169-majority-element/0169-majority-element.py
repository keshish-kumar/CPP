class Solution(object):
    def majorityElement(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        # we have to look ofr more than n/2 times
        temp = 1
        ans = 1
        value = nums[0]
        for i in range(1,len(nums)):
            if nums[i]==value:
                temp+=1
            else:
                temp-=1
                if temp == 0:
                    value = nums[i]
                    temp+=1
        return value    
        