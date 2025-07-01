class Solution {
public:
    int solve(vector<int>& nums, int n,vector<int>& dp){
        if(n>=nums.size()) return 0;
        if(dp[n]!=-1) return dp[n];
        dp[n]= max(solve(nums,n+2,dp)+nums[n],solve(nums,n+3,dp)+nums[n]);
        return dp[n];
    }
    int rob(vector<int>& nums) {
        // vector<int> dp(nums.size()+1,-1);
        // return max(solve(nums,0,dp),solve(nums,1,dp));
        int n = nums.size();
        // 
        vector<int> dp(n+1,0);

        dp[0] = 0;
        dp[1] = nums[0];
        for(int i=2;i<=n;i++){
            int steal = nums[i-1]+dp[i-2];
            int skip = dp[i-1];
        
            dp[i] = max(skip,steal);
        }

        return dp[n];
    }
};