class Solution {
public:
    int solve(vector<int>& coins, int amount, int i,vector<vector<int>>& dp){
        if(amount == 0) return 0;

        if(i>=coins.size() || amount<0) return 1e9;

        if(dp[i][amount] != -1) return dp[i][amount];

        return dp[i][amount] = min(1+solve(coins,amount-coins[i],i,dp),solve(coins,amount,i+1,dp));
    }
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>> dp(coins.size()+1,vector<int>(amount+1,-1));
        int n =  solve(coins,amount,0,dp);
        return n==1e9?-1:n;
    }
};