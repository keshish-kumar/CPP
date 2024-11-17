class Solution {
public:
    int solve(vector<int>& nums, int target, int & ans, int index,vector<vector<int>>& dp){
        if(target == 0){
            ans++;
            return 1;
        }
        if(index==nums.size() || target<0) return 0;
        if(dp[index][target]!=-1) return dp[index][target];

        int l = 0;
        if(target>=nums[index]){
            l = solve(nums,target-nums[index],ans,0,dp);
            
        }
        int r = 0;
        r = solve(nums,target,ans,index+1,dp);
        return dp[index][target] = l+r;

    }
    int combinationSum4(vector<int>& nums, int target) {
        
        int ans =0;

        vector<vector<int>> dp(nums.size(),vector<int>(target+1,-1));
        return solve(nums, target, ans,0,dp);
        return ans;

    }
};