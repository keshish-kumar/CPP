class Solution {
public:
    bool solve(vector<int>& nums, int i, int sum,int acc,vector<vector<int>>& dp){
        if(i>=nums.size()) return false;

        if(sum-acc == acc) return true;
        if(dp[i][acc]!=-1) return dp[i][acc];
        //pick
        return dp[i][acc] =  solve(nums,i+1,sum,acc+nums[i],dp) || solve(nums,i+1,sum,acc,dp);

    }
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int i=0;i<nums.size();i++) sum += nums[i];
        vector<vector< int >> dp(nums.size(),vector<int>(sum,-1));
        return solve(nums,0,sum,0,dp);
    }
};