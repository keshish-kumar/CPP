class Solution {
public:
    bool solve(vector<int>& nums, int i,vector<int>& dp){
        if(i>=(nums.size()-1))return true;
        if(dp[i]!=-1) return dp[i];
        bool ans = false;
        for(int j = 1;j<=nums[i];j++){
           ans = ans || solve(nums,i+j,dp);
        }
        return dp[i]=ans;
    }
    bool canJump(vector<int>& nums) {
        // vector<int> dp(nums.size(),-1);
        // return solve(nums,0,dp);
        
        int maxi = 0;

        for(int i=0;i<nums.size();i++){
            if(i>maxi) return false;
            maxi = max(maxi,i+nums[i]);
        }
        return true;
    }
};