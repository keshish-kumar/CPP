class Solution {
public:
    long long solve(vector<int>& nums, int i,vector<int>& dp){
        if(i==(nums.size()-1)) return 0;
        if(i>=nums.size()) return INT_MAX;
        if(dp[i]!=-1) return dp[i];
        long long ans = INT_MAX;
        for(int index = i+1;index <= (i+nums[i]);index++){
            ans = min(ans,1+solve(nums,index,dp));
        }
        return dp[i] = ans;
    }
    int jump(vector<int>& nums) {
        vector<int> dp(nums.size()+1,-1);
        return solve(nums,0,dp);
    }
};