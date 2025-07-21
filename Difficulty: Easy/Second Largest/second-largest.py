class Solution:
    def getSecondLargest(self, arr):
        # Code Here
        largest = arr[0]
        for i in arr:
            largest = max(largest,i)
        ans = -1
        for i in arr:
            if i!=largest and ans < i:
                ans = i
        return ans
        