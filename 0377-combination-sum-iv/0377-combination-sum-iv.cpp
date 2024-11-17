class Solution {
public:
    int solve(vector<int>& nums, int target,int index,vector<int>& dp){
        if(target == 0){
            return 1;
        }
        if(index==nums.size() || target<0) return 0;
        if(dp[target]!=-1) return dp[target];
       int ans = 0;
       for(int i=index;i<nums.size();i++){
         int l = solve(nums,target-nums[i],0,dp);
            ans += l;
       }
       return dp[target] = ans;

    }
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target+1,-1);
        return solve(nums, target,0,dp);

    }
};