class Solution:
    def lowerbound1(self,nums: List[int], target: int):
        low,high,ans=0,len(nums)-1,-1
        while low<=high:
            mid= (low+high)//2
            if nums[mid]==target:
                ans=mid
            if nums[mid]>=target:
                high=mid-1
            else:
                low=mid+1
        return ans
    def upperbound1(self,nums: List[int], target: int):
        low,high,ans=0,len(nums)-1,-1
        while low<=high:
            mid= (low+high)//2
            if nums[mid]==target:
                ans=mid
            if nums[mid]<=target:
                low=mid+1
            else:
                high=mid-1;
        return ans
    def searchRange(self, nums: List[int], target: int) -> List[int]:
        return (self.lowerbound1(nums,target),self.upperbound1(nums,target))