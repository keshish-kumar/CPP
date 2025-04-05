class Solution {
public:
    bool solve(vector<int>& nums, int target, int i,vector<vector<int>>& dp){
        if(target == 0) return true;
        if(target<0 || i>=nums.size()) return false;
        if(dp[i][target]!=-1) return dp[i][target];
        dp[i][target] = solve(nums,target-nums[i],i+1,dp) || solve(nums,target,i+1,dp);
        return dp[i][target];
    }
    bool canPartition(vector<int>& nums) {
        //. equal partititon can onky be performed when sum is even number odd number cannot be partriitoned equally
        int sum = accumulate(nums.begin(),nums.end(),0);
        if(sum%2!=0) return false;

        int target = sum/2;
        vector<vector<int> > dp(nums.size(),vector<int>(target+1,-1));
        return solve(nums,target,0,dp);
        
    }
};