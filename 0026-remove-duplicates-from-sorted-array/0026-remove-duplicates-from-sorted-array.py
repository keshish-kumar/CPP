class Solution(object):
    def removeDuplicates(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        i=0
        j=0
        ans=1
        for j in range(0,len(nums)):
            if nums[i]!=nums[j]:
                i+=1
                ans+=1
                nums[i],nums[j]=nums[j],nums[i]


        return ans

        