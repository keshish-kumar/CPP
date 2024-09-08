class Solution {
public:

    int house(vector<int>& nums, int i,vector<int>& dp){
        if(i>=nums.size()) return 0;
        
        if(dp[i]!=-1) return dp[i];
       int steal = nums[i]+ house(nums,i+2,dp);
       int skip = house(nums,i+1,dp);
        return dp[i] = max(steal,skip);
    }    

    int rob(vector<int>& nums) {
        // House robber
        vector<int> dp(nums.size()+1,-1);
        return house(nums,0,dp);



        
    }
};