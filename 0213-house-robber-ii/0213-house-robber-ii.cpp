class Solution {
public:
    int solve(vector<int>& nums, int i, int n,vector<int>& dp){
        if(i>=n) return 0;
        if(dp[i]!=-1) return dp[i];
        return dp[i] = max(nums[i]+solve(nums,i+2,n,dp),solve(nums,i+1,n,dp));
    }
    int rob(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        vector<int> dp1(nums.size(),-1);
        vector<int> dp2(nums.size(),-1);
        return max(solve(nums,0,nums.size()-1,dp1),solve(nums,1,nums.size(),dp2));
    }
};