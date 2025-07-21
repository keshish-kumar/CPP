class Solution:
    def longestSubarray(self, arr, k):  
        # code here
        mp = {}
        sum =0
        ans=0;
        for i in range(0,len(arr)):
            sum+=arr[i]
            if sum == k:
                ans = max(ans,i+1)
            if sum-k in mp:
                ans = max(ans,i-mp[sum-k])
            if sum not in mp:
                mp[sum]=i;
        return ans
        
    
