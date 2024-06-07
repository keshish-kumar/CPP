class Solution {
public:
    bool partition(vector<int>& nums, int sum, int n , vector<vector<int>>& dp){
        
        if(sum == 0) return true;
        
        if(n==0 ) return nums[n]==sum;
        
        if(dp[n][sum]!=-1) return dp[n][sum];
        
        int notpick = partition(nums,sum,n-1,dp);
        
        int pick = false;
        
        if(sum>=nums[n])
                pick = partition(nums,sum-nums[n],n-1,dp);
        
        return dp[n][sum] = notpick||pick;
        
    }
    bool canPartition(vector<int>& nums) {
        
        int sum = 0;
        int n = nums.size();
        for(int i=0;i<nums.size();i++)
                sum += nums[i];
        
       
        
        if(sum%2 != 0) return false;
         sum = sum/2;
        vector<vector<int>> dp(n,vector<int>(sum+1,-1));
        
        return partition(nums,sum,n-1,dp);
    }
};