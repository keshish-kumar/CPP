class Solution(object):
    def sortColors(self, nums):
        """
        :type nums: List[int]
        :rtype: None Do not return anything, modify nums in-place instead.
        """
        i=0
        j=0
        last =len(nums)-1

        while j<=last:
            if nums[j]==0:
                nums[i],nums[j] = nums[j],nums[i]
                i+=1
                j+=1
            elif nums[j]==1:
                j+=1
            else:
                nums[j],nums[last] = nums[last],nums[j]
                last-=1
            
            
