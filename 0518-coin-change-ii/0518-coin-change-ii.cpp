class Solution {
public:
    int solve(int amount, vector<int>& coins, int i,vector<vector<int>>& dp){
        if(amount==0) return 1;
        if(i>=coins.size()){
            return 0;
        }
        if(dp[i][amount]!=-1) return dp[i][amount];
        int l=0;
        if(amount>=coins[i]){
            l =   solve(amount-coins[i],coins,i,dp);
        }
        return dp[i][amount] = l+solve(amount,coins,i+1,dp);
    }
    int change(int amount, vector<int>& coins) {
        vector<vector<int>> dp(coins.size(),vector<int>(amount+1,-1));
        return solve(amount,coins,0,dp);
    }
};