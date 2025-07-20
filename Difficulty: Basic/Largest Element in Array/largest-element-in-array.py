class Solution:
    def largest(self, arr):
        # code here
        ans=arr[0];
        for i in arr:
            ans = max(ans,i)
        return ans;
        
