class Solution(object):
    def rotate(self, nums, k):
        l = len(nums)
        my_list = [0]*l
        for i in range(0,len(nums)):
            j = (i+k)%l
            my_list[j] = nums[i]
        nums[:] =  my_list

        