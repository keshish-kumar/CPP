class Solution:
    def check(self, nums: List[int]) -> bool:
        # ONly one time peak will be found in the array
        ans = 0
        el = nums[0]
        for i in range(1,len(nums)):
            if nums[i-1] > nums[i]:
                ans+=1
        if nums[-1]>nums[0]:
             ans+=1
        return ans<2
        