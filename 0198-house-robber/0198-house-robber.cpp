class Solution {
public:
    int profit(vector<int>& nums, int n,vector<int>& dp){
        if(n==0) return nums[n];
        if(n<0) return 0;
        if(dp[n]!=-1) return dp[n];
        int pick = nums[n]+profit(nums,n-2,dp);
        int notpick = profit(nums,n-1,dp);
        dp[n]  = max(pick,notpick);
        return dp[n];
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,-1);
        return profit(nums,n-1,dp);
    }
};