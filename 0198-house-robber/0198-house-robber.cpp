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
        vector<int> dp(nums.size()+1,0);
        //return house(nums,0,dp);
        dp[0] = 0; // when no house is present;

        dp[1] = nums[0]; // when only one house is present

        for(int i=2;i<=nums.size();i++){

            int steal = nums[i-1]+ dp[i-2]; // nums[i-1] beacuse that is. the index for that position as it is starting forom 0
            int skip = dp[i-1];
            dp[i] = max(steal,skip);
        }
        return dp[nums.size()];
        
    }
};