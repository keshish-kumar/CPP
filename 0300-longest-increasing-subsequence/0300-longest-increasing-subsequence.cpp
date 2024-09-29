class Solution {
public:
    int solve(vector<int>& nums, int prev, int index,vector<vector<int>>& dp){
        // base condition
        if(index>=nums.size()){
        
           return 0;
        }

        if(dp[index][prev+1]!=-1) return dp[index][prev+1];
        // pick that element
        int pick = INT_MIN;
        if(prev==-1 || nums[prev]<nums[index]){

            pick = 1+ solve(nums,index,index+1,dp);
            
        }

        // not picking that element
        int notpick = solve(nums,prev,index+1,dp);
        return dp[index][prev+1] = max(pick,notpick);

    }
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size(),1);
        for(int i=0;i<nums.size();i++){
            for(int j=0;j<i;j++){
                if(nums[j]<nums[i]){
                    int n = dp[j]+1;
                    dp[i] = max(dp[i],n);
                }
            }
        }
        int ans = 0;
        for(int i=0;i<nums.size();i++){
            ans = max(ans,dp[i]);
        }
        return ans;
    }
};