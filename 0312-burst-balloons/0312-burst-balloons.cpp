class Solution {
public:
    int solve(vector<int>& nums, int i, int j, vector<vector<int>>& dp){
        if(i>j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int maxi = INT_MIN;
        for(int index = i;index<=j;index++){
            int temp = solve(nums,i,index-1,dp)+solve(nums,index+1,j,dp)+(nums[i-1]*nums[index]*nums[j+1]);
            maxi = max(maxi,temp);
        }

        return dp[i][j] =  maxi;
    }
    int maxCoins(vector<int>& nums) {


        nums.insert(nums.begin(),1);
        nums.push_back(1);
        vector<vector<int>> dp(nums.size()+1,vector<int>(nums.size()+1,-1));
        return solve(nums,1,nums.size()-2,dp);

    }
};