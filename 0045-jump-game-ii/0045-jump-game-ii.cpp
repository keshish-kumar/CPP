class Solution {
public:
    int solve(vector<int>& nums, int i,vector<int>& dp){
        if(i>=nums.size()-1) return 0;
        if(dp[i]!=-1) return dp[i];
        int ans = nums.size()-1;
        for(int j=nums[i];j>0;j--){
            ans = min(ans,1+solve(nums,j+i,dp));
        }

        return dp[i] =  ans;
    }
    int jump(vector<int>& nums) {
        
        vector<int> dp(nums.size(),-1);
        return solve(nums,0,dp);
        
    }
};