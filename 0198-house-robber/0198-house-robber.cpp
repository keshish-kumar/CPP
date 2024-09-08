class Solution {
public:

    int house(vector<int>& nums, int i,vector<int>& dp){
        if(i>=nums.size()) return 0;
        int maxi = 0;
        if(dp[i]!=-1) return dp[i];
        for(int k=i;k<nums.size();k++){
            int temp = nums[k]+house(nums,k+2,dp);
            maxi = max(maxi,temp);
        }
        return dp[i] = maxi;
    }    

    int rob(vector<int>& nums) {
        // House robber
        vector<int> dp(nums.size()+1,-1);
        return house(nums,0,dp);
    }
};