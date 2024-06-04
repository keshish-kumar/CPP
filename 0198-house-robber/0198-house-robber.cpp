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
       // return profit(nums,n-1,dp);
        dp[0] = nums[0];
        for(int i=1;i<n;i++){
            int pick = nums[i];
            if(i-2 >= 0)
             pick += dp[i-2];
            
            int  notpick = dp[i-1];
            dp[i] = max(pick,notpick);
        }
        return dp[n-1];
    }
};