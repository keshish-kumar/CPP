class Solution {
public:
    int solve(vector<int>& nums, int n,vector<int>& dp){
        if(n>=nums.size()) return 0;
        if(dp[n]!=-1) return dp[n];
        dp[n]= max(solve(nums,n+2,dp)+nums[n],solve(nums,n+3,dp)+nums[n]);
        return dp[n];
    }
    int rob(vector<int>& nums) {
        // vector<int> dp(nums.size()+1,-1);
        // return max(solve(nums,0,dp),solve(nums,1,dp));
        int n = nums.size();
        if(n==1) return nums[0];
        if(n==2) return max(nums[0],nums[1]);

        int n1 = nums[0];
        int n2 = nums[1];
        int n3 = nums[0]+nums[2];

        for(int i=3;i<nums.size();i++){
            int temp = max(n1+nums[i],n2+nums[i]);
            n1 = n2;
            n2 = n3;
            n3 = temp;
        }
        return max({n1,n2,n3});
    }
};